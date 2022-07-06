#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <sstream>
#include <regex>

using namespace std;

vector<string> solution(vector<string> record)
{
    vector<string> answer_temp;
    vector<string> answer;

    map<string, string> id_name;

    for (int i = 0; i < record.size(); i++)
    {
        istringstream iRecord(record[i]);
        string cmd;
        string id;
        string name;

        getline(iRecord, cmd, ' ');
        getline(iRecord, id, ' ');

        if (cmd != "Leave")
        {
            getline(iRecord, name, ' ');

            id_name[id] = name;
        }

        if (cmd != "Change")
        {
            string str = id + " ";
            if (cmd == "Enter")
            {
                str += "들어왔습니다.";
            }
            else if (cmd == "Leave")
            {
                str += "나갔습니다.";
            }

            answer_temp.push_back(str);
        }
    }

    auto iter = id_name.begin();

    // while (iter != id_name.end())
    // {
    //     cout << iter->first << ": " << iter->second << endl;
    //     iter++;
    // }

    for (int i = 0; i < answer_temp.size(); i++)
    {
        istringstream iAnswer(answer_temp[i]);
        string id;
        string name;
        getline(iAnswer, id, ' ');
        name = id_name[id] + "님이";
        string str = regex_replace(answer_temp[i], regex(id), name);
        answer.push_back(str);
    }

    return answer;
}

int main()
{
    vector<string> answer;

    // answer = solution({"Enter uid1234 Muzi", "Enter Uid1234 Prodo", "Leave uid1234", "Enter uid1234 Prodo", "Change Uid1234 Ryan"});
    answer = solution({"Enter abc123 A", "Change abc123 B", "Enter abb B", "Leave abc123"});

    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer[i] << endl;
    }
    return 0;
}