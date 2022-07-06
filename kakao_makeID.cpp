#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string new_id)
{
    string answer = "";
    string copy = new_id;

    for (int i = 0; i < copy.size(); i++)
    {
        // 대문자인 경우
        if (isupper(copy[i]))
        {
            copy[i] = tolower(copy[i]);
        }

        // 허용하지 않는 문자
        if (!isupper(copy[i]) && !islower(copy[i]) && isdigit(copy[i]) == 0 && copy[i] != '-' && copy[i] != '_' && copy[i] != '.')
        {
            copy.erase(i, 1);
            i--; // index가 1씩 당겨졌으로 index-1
        }
        // 마침표 문자 중복 제거
        if (copy[i] == '.')
        {
            while (copy[i + 1] == '.')
            {
                copy.erase(i + 1, 1);
            }
        }
    }
    // id [0], [-1] 인덱스에 '.' 불가
    while (copy[0] == '.' || copy[copy.size() - 1] == '.')
    {
        if (copy[0] == '.')
            copy.erase(0, 1);
        if (copy[copy.size() - 1] == '.')
            copy.erase(copy.size() - 1, 1);
    }
    if (copy.size() > 15)
    {
        copy.erase(15);
        if (copy[copy.size() - 1] == '.')
            copy.erase(copy.size() - 1);
    }

    while (copy.size() < 3)
    {
        if (copy.size() == 0)
            copy = 'a';

        else
            copy += copy[copy.size() - 1];
    }
    answer = copy;
    return answer;
}

int main()
{
    string answer = solution("...!@BaT#*..y.abcdefghijklm");
    cout << answer << endl;

    cout << solution("=.=") << endl;
    cout << solution("z-+.^.") << endl;
    cout << solution("123_.def") << endl;
    cout << solution("abcdefghijklmn.p") << endl;
}