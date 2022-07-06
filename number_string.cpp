#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(string s)
{
    vector<string> number = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    string answerStr;
    int answer = 0;

    for (int i = 0; i < s.size();)
    {
        string temp;
        if (isdigit(s[i]) != 0) //숫자
        {
            answerStr += s[i];
            i++;
        }
        while (isdigit(s[i]) == 0) //문자열
        {
            temp += s[i];
            i++;
            auto isNumber = find(number.begin(), number.end(), temp);
            if (isNumber != number.end())
            {
                answerStr += to_string(isNumber - number.begin());
                break;
            }
        }
    }
    answer = stoi(answerStr);
    return answer;
}

int main()
{
    int answer = 0;
    answer = solution("one4seveneight");
    cout << answer << endl;
    answer = solution("23four5six7");
    cout << answer << endl;
    return 0;
}