#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k)
{
    vector<int> answer;
    map<string, int> reportedCount;       // 유저별 신고당한 횟수
    map<string, vector<string>> reported; // 유저별 신고 기록
    vector<string> suspensionUser;        //계정 정지 회원 목록

    // 유저별 신고횟수 초기화
    for (int i = 0; i < id_list.size(); i++)
    {
        reportedCount[id_list[i]] = 0;
    }

    for (int i = 0; i < report.size(); i++)
    {
        istringstream iReport(report[i]);
        string user1;
        string user2;
        getline(iReport, user1, ' ');
        getline(iReport, user2, ' ');

        // cout << "reporter: " << user1 << endl;
        // cout << "reported: " << user2 << endl;

        vector<string> _list = reported[user1];

        // 새로운 신고건
        if (find(_list.begin(), _list.end(), user2) == _list.end())
        {
            reported[user1].push_back(user2);
            reportedCount[user2]++;
            if (reportedCount[user2] == k) // 신고건이 기준 횟수를 넘음
            {
                suspensionUser.push_back(user2);
            }
        }
    }

    // 신고 리스트 출력
    // for (int i = 0; i < id_list.size(); i++)
    // {
    //     cout << id_list[i] << ": ";

    //     for (int j = 0; j < reported[id_list[i]].size(); j++)
    //     {
    //         cout << reported[id_list[i]][j] << " ";
    //     }
    //     cout << endl;

    //     cout << id_list[i] << ": " << reportedCount[id_list[i]] << endl;
    // }

    for (int i = 0; i < id_list.size(); i++)
    {
        vector<string> _list = reported[id_list[i]];
        int count = 0; // 메일 횟수
        for (int j = 0; j < suspensionUser.size(); j++)
        {
            // 계정 정지된 회원을 신고한 적이 있음
            if (find(_list.begin(), _list.end(), suspensionUser[j]) != _list.end())
            {
                count++;
            }
        }
        answer.push_back(count);
    }

    return answer;
}

int main()
{
    vector<int> answer;

    answer = solution({"muzi", "frodo", "apeach", "neo"}, {"muzi frodo", "apeach frodo", "frodo neo", "muzi neo", "apeach muzi"}, 2);
    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer[i] << " ";
    }
    cout << endl;
    answer = solution({"con", "ryan"}, {"ryan con", "ryan con", "ryan con", "ryan con"}, 3);
    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer[i] << " ";
    }
    cout << endl;
    answer = solution({"a", "b", "c"}, {"a b", "a b", "a b", "c b"}, 3);
    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer[i] << " ";
    }
    return 0;
}