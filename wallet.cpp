#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmpHeight(const vector<int> &v1, const vector<int> &v2)
{
    return v1[1] > v2[1];
}

bool cmpWidth(const vector<int> &v1, const vector<int> &v2)
{
    return v1[0] > v2[0];
}
int solution(vector<vector<int>> sizes)
{
    int answer = 0;
    int wMax = sizes[0][0];
    int hMax = sizes[0][1];
    for (int i = 1; i < sizes.size(); i++)
    {
        wMax < sizes[i][0] ? wMax = sizes[i][0] : NULL;
        hMax < sizes[i][1] ? hMax = sizes[i][1] : NULL;
    }

    int idx = 0;
    if (wMax > hMax) // 가로 길이 확정 -> 세로 길이가 긴 경우 회전 시키는 게 이득이라면 회전
    {
        sort(sizes.begin(), sizes.end(), cmpHeight);
        for (int idx = 0; idx < sizes.size(); idx++)
        {
            if (sizes[idx][0] < sizes[idx][1])
            {
                int temp = sizes[idx][0];
                sizes[idx][0] = sizes[idx][1];
                sizes[idx][1] = temp;
            }
        }
        sort(sizes.begin(), sizes.end(), cmpHeight);
        hMax = sizes[0][1];
        answer = wMax * hMax;
    }

    else
    {
        sort(sizes.begin(), sizes.end(), cmpWidth);
        for (int idx = 0; idx < sizes.size(); idx++)
        {
            if (sizes[idx][0] > sizes[idx][1])
            {
                int temp = sizes[idx][0];
                sizes[idx][0] = sizes[idx][1];
                sizes[idx][1] = temp;
            }
        }
        sort(sizes.begin(), sizes.end(), cmpWidth);
        wMax = sizes[0][0];
        answer = wMax * hMax;
    }

    // for (int i = 0; i < sizes.size(); i++)
    // {
    //     cout << sizes[i][0] << "\t" << sizes[i][1] << endl;
    // }

    return answer;
}

int main()
{
    cout << solution({{60, 50}, {20, 70}, {60, 30}, {80, 40}, {30, 70}}) << endl;
    cout << solution({{10, 7}, {12, 3}, {8, 15}, {14, 7}, {5, 15}}) << endl;
}