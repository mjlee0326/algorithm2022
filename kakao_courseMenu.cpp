#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

map<string, int> cntCourse;
string str;

bool comp(pair<string, int> &a, pair<string, int> &b)
{
    return a.second > b.second;
}

void print_pair(vector<pair<string, int>> &v)
{
    auto iter = v.begin();
    while (iter != v.end())
    {
        cout << iter->first << "\t" << iter->second << endl;
        iter++;
    }
    cout << endl;
}

void print_map(map<string, int> m)
{
    for (auto idx : m)
    {
        cout << idx.first << "\t" << idx.second << endl;
    }
}

void combination(string order, int num, int idx)
{
    // 주문 수 보다 조합 개수가 많을 경우 바로 return
    if (order.size() < num)
    {
        return;
    }
    // str: 조합 문자열. 조합 개수를 만족했으므로 map에 기록 후 return
    if (str.size() == num)
    {
        // 기존에 있던 조합이라면 value+1, 처음 보는 조합이라면 map에 삽입
        cntCourse.find(str) != cntCourse.end() ? cntCourse[str]++ : cntCourse[str] = 1;
        return;
    }
    // 재귀 DFS로 조합 생성
    for (int i = idx; i < order.size(); i++)
    {
        str += order[i];
        combination(order, num, i + 1);
        str = str.substr(0, str.size() - 1); // 다음 조합을 위해 원소 하나 제거
    }
}

vector<string> solution(vector<string> orders, vector<int> course)
{
    vector<string> answer;

    // &를 붙여야 기존 주소값에 저장됨
    for (auto &idx : orders)
    {
        sort(idx.begin(), idx.end());
    }

    // 코스 단품 메뉴 개수에 대한 반복문
    for (int i = 0; i < course.size(); i++)
    {
        cntCourse.clear(); // 새로운 개수의 조합을 구하는 것이므로 map 초기화

        // 각 손님들의 주문에 대한 반복문
        for (int j = 0; j < orders.size(); j++)
        {
            combination(orders[j], course[i], 0);

            // 다른 손님 주문으로 넘어가기 전에 str 초기화
            str.empty();
        }

        // map에 저장된 조합이 있다면
        if (!cntCourse.empty())
        {
            // map을 value 기준으로 sort하기 위한 pair Class 사용
            vector<pair<string, int>> v(cntCourse.begin(), cntCourse.end());
            sort(v.begin(), v.end(), comp);
            // print_pair(v);
            auto iter = v.begin();

            // 2명 이상이 주문한 조합이어야 함
            if (iter->second > 1)
            {
                int popular_course = iter->second;

                // 가장 많이 주문된 메뉴 조합이 여러 개라면 모두 추가
                while (popular_course == iter->second)
                {
                    answer.push_back(iter->first);
                    iter++;
                }
            }
            // print_map(cntCourse);
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}

int main()
{
    vector<string> answer;
    //{"AC", "ACDE", "BCFG", "CDE"}
    // answer = solution({"abcfg", "ac", "cde", "acde", "bcfg", "acdeh"}, {2, 3, 4});
    // for (auto idx : answer)
    //     cout << idx << "\t";
    // cout << endl;

    answer = solution({"XYZ", "XWY", "WXA"}, {2, 3, 4});
    for (auto idx : answer)
        cout << idx << "\t";
    cout << endl;
}