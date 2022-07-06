#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
vector<string> answer;
bool done = false;

// idx: 현재 경로
int dfs(vector<vector<string>> tickets, vector<bool> &visited, int idx)
{
    if (answer.size() == tickets.size())
    {
        answer.push_back(tickets[idx][1]);
        return 0;
    }
    visited[idx] = true;
    answer.push_back(tickets[idx][0]);
    int nextIdx;
    vector<int> idxs;

    for (int i = 0; i < tickets.size(); i++)
    {
        if (!visited[i])
        {
            // idx의 목적지와 i의 출발지 일치
            if (tickets[i][0] == tickets[idx][1])
            {
                dfs(tickets, visited, i);
            }
        }
    }
    if (!done)
    {

        if (answer.size() != tickets.size())
        {
            answer.pop_back();
            visited[idx] = false;
        }
        else
        {
            answer.push_back(tickets[idx][1]);
            done = true;
        }
    }

    return 0;
}

vector<string> solution(vector<vector<string>> tickets)
{
    vector<bool> visited(tickets.size(), false);
    string ahead;
    int idx;
    sort(tickets.begin(), tickets.end());

    for (int i = 0; i < tickets.size(); i++)
    {
        if (tickets[i][0] == "ICN" && !visited[i])
        {
            dfs(tickets, visited, i);
        }
        if (done)
        {
            return answer;
        }
    }
    return answer;
}

int main()
{
    solution({{"ICN", "SFO"}, {"ICN", "ATL"}, {"SFO", "ATL"}, {"ATL", "ICN"}, {"ATL", "SFO"}});
    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer[i] << " ";
    }
    cout << endl
         << endl;

    answer.clear();
    done = false;
    solution({{"ICN", "BBB"}, {"ICN", "CCC"}, {"BBB", "CCC"}, {"CCC", "BBB"}, {"CCC", "ICN"}});
    // solution({{"ICN", "B"}, {"B", "ICN"}, {"ICN", "A"}, {"A", "D"}, {"D", "A"}});
    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer[i] << " ";
    }
    cout << endl;
    return 0;
}