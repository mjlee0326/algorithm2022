#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

bool comp(pair<string, int> &a, pair<string, int> &b)
{
    return a.second < b.second;
}

vector<string> solution(vector<vector<string>> friends, string user_id)
{
    vector<string> answer;
    map<string, vector<string>> user_friends;
    map<string, int> mutual;

    vector<string> users;
    vector<string> Dfriends; // 이미 친구인 목록

    for (int i = 0; i < friends.size(); i++)
    {
        for (int j = 0; j < 2; j++)
        {
            if (find(users.begin(), users.end(), friends[i][j]) == users.end())
            {
                users.push_back(friends[i][j]);
                mutual[friends[i][j]] = 0; // mutual friend 초기화
            }
            if (friends[i][j] == user_id) // 당사자와 이미 친구라면
            {
                // cout << "이미 친구: " << friends[i][(j + 1) % 2] << endl;
                Dfriends.push_back(friends[i][(j + 1) % 2]);
                break;
                // mutual[friends[i][(j + 1) % 2]] = -1; // 추천 대상 아님
            }
        }
    }

    for (int i = 0; i < users.size(); i++)
    {
        // cout << Dfriends[i] << endl;
        mutual[users[i]] = 0;
    }

    for (int k = 0; k < Dfriends.size(); k++)
    {
        for (int i = 0; i < friends.size(); i++)
        {
            for (int j = 0; j < 2; j++)
            {
                if (friends[i][j] == Dfriends[k]) // mutual
                {
                    mutual[friends[i][(j + 1) % 2]] += 1;
                    break;
                }
            }
        }
    }

    // mutual["james"] = 0;
    vector<pair<string, int>> v(mutual.begin(), mutual.end());
    sort(v.begin(), v.end(), comp);

    auto iterEnd = v.end() - 1;
    // int cnt;
    int cnt = iterEnd->second;
    while (iterEnd->first == user_id || find(Dfriends.begin(), Dfriends.end(), iterEnd->first) != Dfriends.end())
    {
        iterEnd--;
        cnt = iterEnd->second;
    }

    sort(v.begin(), v.end());
    auto iter = v.begin();
    while (iter != v.end())
    {
        // cout << iter->first << ": " << iter->second << endl;

        if (iter->second == cnt && iter->first != user_id && find(Dfriends.begin(), Dfriends.end(), iter->first) == Dfriends.end())
        {
            answer.push_back(iter->first);
        }
        iter++;
    }

    return answer;
}

int main()
{
    vector<string> answer;
    answer = solution({{"david", "frank"}, {"demi", "david"}, {"frank", "james"}, {"demi", "james"}, {"claire", "frank"}}, "david");

    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer[i] << " ";
    }
    return 0;
}