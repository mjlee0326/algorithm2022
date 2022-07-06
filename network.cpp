#include <iostream>
#include <string>
#include <vector>

using namespace std;

int dfs(vector<vector<int>> computers, vector<bool> &visited, int idx)
{
    visited[idx] = true;
    for (int i = 0; i < computers[idx].size(); i++)
    {
        if (computers[idx][i] == 1 && !visited[i])
        {
            dfs(computers, visited, i);
        }
    }
    return 0;
}

int solution(int n, vector<vector<int>> computers)
{
    int answer = 0;
    vector<bool> visited(n, false);

    for (int i = 0; i < computers.size(); i++)
    {
        if (!visited[i])
        {
            dfs(computers, visited, i);
            answer++;
        }
    }
    return answer;
}

int main()
{
    cout << solution(3, {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}}) << endl;
    cout << solution(3, {{1, 1, 0}, {1, 1, 1}, {0, 1, 1}}) << endl;

    return 0;
}