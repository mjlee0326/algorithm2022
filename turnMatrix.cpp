#include <iostream>
#include <string>
#include <vector>

using namespace std;

void printMatrix(vector<vector<int>> matrix)
{
    for (auto i : matrix)
    {
        for (auto idx : i)
        {
            cout << idx << "\t";
        }
        cout << endl;
    }
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries)
{
    vector<int> answer;
    vector<vector<int>> matrix(rows, vector<int>(columns, 0));

    int cnt = 1;
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            matrix[i][j] = cnt++;
        }
    }

    for (int i = 0; i < queries.size(); i++)
    {
        int Srow = queries[i][0] - 1;
        int Scol = queries[i][1] - 1;
        int Erow = queries[i][2] - 1;
        int Ecol = queries[i][3] - 1;
        int pre = matrix[Srow][Scol];
        int next = matrix[Srow][Scol + 1];
        int min = matrix[Srow][Scol];

        // 상단 이동
        for (int j = Scol; j < Ecol; j++)
        {
            matrix[Srow][j + 1] = pre;
            pre = next;
            j + 2 < columns ? next = matrix[Srow][j + 2] : next = 0;
            min > pre ? min = pre : NULL;
        }
        next = matrix[Srow + 1][Ecol];

        // 우측 이동
        for (int j = Srow; j < Erow; j++)
        {
            matrix[j + 1][Ecol] = pre;
            pre = next;
            j + 2 < rows ? next = matrix[j + 2][Ecol] : next = 0;
            min > pre ? min = pre : NULL;
        }
        next = matrix[Erow][Ecol - 1];

        // 하단 이동
        for (int j = Ecol; j > Scol; j--)
        {
            matrix[Erow][j - 1] = pre;
            pre = next;
            j - 2 >= 0 ? next = matrix[Erow][j - 2] : next = 0;
            min > pre ? min = pre : NULL;
        }
        next = matrix[Erow - 1][Scol];

        // 좌측 이동
        for (int j = Erow; j > Srow; j--)
        {
            matrix[j - 1][Scol] = pre;
            pre = next;
            j - 2 >= 0 ? next = matrix[j - 2][Scol] : next = 0;
            min > pre ? min = pre : NULL;
        }
        answer.push_back(min);
    }
    return answer;
}
int main()
{
    vector<int> answer;
    answer = solution(6, 6, {{2, 2, 5, 4}, {3, 3, 6, 6}, {5, 1, 6, 3}});
    for (auto idx : answer)
        cout << idx << "\t";
    cout << endl;
    answer = solution(3, 3, {{1, 1, 2, 2}, {1, 2, 2, 3}, {2, 1, 3, 2}, {2, 2, 3, 3}});
    for (auto idx : answer)
        cout << idx << "\t";
    cout << endl;
    answer = solution(100, 97, {{1, 1, 100, 97}});
    for (auto idx : answer)
        cout << idx << "\t";
    cout << endl;
}