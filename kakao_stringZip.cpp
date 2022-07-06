#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string s)
{
    int answer = s.size();
    string temp;
    for (int i = 1; i < s.size(); i++) // i: 몇 단위씩 자를 건지
    {
        string cur = s.substr(0, i);
        int cnt = 0;
        for (int j = 0; j < s.size(); j++)
        {
            string compare = s.substr(j * i, i);

            if (cur == compare)
            {
                cnt++;
            }
            if (cur != compare)
            {
                cnt == 1 ? temp += cur : temp += to_string(cnt) + cur;
                cur = s.substr(j * i, i);
                cnt = 1;
            }
            if ((j + 1) * i >= s.size())
            {
                cnt == 1 ? temp += compare : temp += to_string(cnt) + compare;
                // cout << temp << endl;
                answer > temp.size() ? answer = temp.size() : NULL;
                break;
            }
        }
        temp = "";
    }

    return answer;
}

int main()
{
    cout << solution("aabbaccc") << endl;
    cout << solution("ababcdcdababcdcd") << endl;
    cout << solution("aaaaaaaaaaaabcd") << endl;
    cout << solution("aaaaaaaaaaaaaaabbbbbbbbbbc") << endl;
}
