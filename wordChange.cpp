#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int answer = 0;

int dfs(string cur, string target, vector<string> words, vector<bool> &visited)
{

    for (int i = 0; i < words.size(); i++)
    {
        if (!visited[i]) // 방문하지 않은 노드 중에서만 탐색
        {
            int count = 0;
            int targetCount = 0;
            string temp;
            for (int j = 0; j < words[i].size(); j++)
            {
                if (cur[j] != words[i][j])
                {
                    count++;
                    temp += words[i][j];
                }
                else
                {
                    temp += cur[j];
                }

                if (cur[j] != target[j])
                {
                    targetCount++;
                }
            }
            if (targetCount == 1)
            {
                answer++;
                visited[i] = true;
                return answer;
            }
            else if (count == 1) // 글자 수가 하나만 차이가 난다면
            {
                answer++;
                visited[i] = true;
                dfs(temp, target, words, visited);
            }
        }
    }
    return answer;
}

int solution(string begin, string target, vector<string> words)
{
    if (find(words.begin(), words.end(), target) == words.end())
    {
        return answer;
    }

    vector<bool> visited(words.size(), false);

    dfs(begin, target, words, visited);
    return answer;
}

int main()
{
    cout << solution("hit", "cog", {"hot", "dot", "dog", "lot", "log", "cog"}) << endl;
    return 0;
}
