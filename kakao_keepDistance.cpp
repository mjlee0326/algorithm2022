#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#define N 5

using namespace std;

bool isKeep(vector<string> place)
{
    for (int i = 0; i < place.size(); i++)
    {
        for (int j = 0; j < place[i].size(); j++)
        {
            // (i, j)에 응시자가 앉아 있으므로 거리두기 확인 시작
            if (place[i][j] == 'P')
            {
                // cout << "(" << i << ", " << j << ") 확인" << endl;

                // (i, j) 기준으로 3X3 검사를 위한 인덱스 설정
                int startI, startJ;
                i > 0 ? startI = i - 1 : startI = 0;
                j > 0 ? startJ = j - 1 : startJ = 0;

                int endI, endJ;
                i + 1 < N ? endI = i + 1 : endI = i;
                j + 1 < N ? endJ = j + 1 : endJ = j;

                // cout << "endI: " << endI << "\tendJ: " << endJ << endl;
                for (int curI = startI; curI <= endI; curI++)
                {
                    for (int curJ = startJ; curJ <= endJ; curJ++)
                    {
                        // cout << "curI: " << curI << "\tcurJ: " << curJ << endl;

                        // 절대값 abs()함수로 거리 구하기
                        int distance = abs(curI - i) + abs(curJ - j);

                        // 맨해튼 거리 2 이하인 곳에 다른 사람이 앉아 있음
                        if (place[curI][curJ] == 'P' && distance > 0 && distance < 3)
                        {
                            // 거리 1이므로 무조건 false
                            if (distance == 1)
                            {
                                return false;
                            }

                            // 파티션이 없으므로 false
                            if (place[i][curJ] != 'X' || place[curI][j] != 'X')
                            {
                                return false;
                            }
                        }

                        // (i, j)와 행 또는 열이 같으며 거리가 2인 자리에 다른 응시자가 앉아 있는데
                        // 그 중간에 파티션이 없다면 false
                        if (distance == 1 && place[curI][curJ] != 'X')
                        {
                            if (curI == i)
                            {
                                if (curJ > j && curJ + 1 < N && place[curI][curJ + 1] == 'P')
                                {
                                    return false;
                                }
                                if (curJ < j && curJ - 1 >= 0 && place[curI][curJ - 1] == 'P')
                                {
                                    return false;
                                }
                            }
                            if (curJ == j)
                            {
                                if (curI > i && curI + 1 < N && place[curI + 1][curJ] == 'P')
                                {
                                    return false;
                                }
                                if (curI < i && curI - 1 >= 0 && place[curI - 1][curJ] == 'P')
                                {
                                    return false;
                                }
                            }
                        }
                    }
                }
                // cout << "(" << i << ", " << j << ") 통과" << endl;
            }
        }
        // cout << endl;
    }
    return true;
}

vector<int> solution(vector<vector<string>> places)
{
    vector<int> answer;

    for (int i = 0; i < places.size(); i++)
    {
        isKeep(places[i]) == 0 ? answer.push_back(0) : answer.push_back(1);
    }

    return answer;
}

int main()
{
    vector<int> answer;
    answer = solution({{"POOOP", "OXXOX", "OPXPX", "OOXOX", "POXXP"}, {"POOPX", "OXPXP", "PXXXO", "OXXXO", "OOOPP"}, {"PXOPX", "OXOXP", "OXPOX", "OXXOP", "PXPOX"}, {"OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO"}, {"PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP"}});
    for (auto &idx : answer)
        cout << idx << "\t";
    cout << endl;

    answer = solution({{"XXXXX", "XXXXX", "XXXXX", "XXXXX", "XXPOP"}});
    for (auto &idx : answer)
        cout << idx << "\t";
    cout << endl;
}