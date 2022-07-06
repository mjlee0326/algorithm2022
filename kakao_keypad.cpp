#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#define NOT_MID 0
#define MID 1

using namespace std;

string solution(vector<int> numbers, string hand)
{
    string answer = "";
    vector<int> left = {1, 4, 7};
    vector<int> right = {3, 6, 9};
    vector<int> mid = {2, 5, 8, 0};
    map<string, vector<int>> curHand;
    curHand["right"] = {-1, 3, NOT_MID}; // [0]: 현재 숫자(*, #은 -1), [1]: 인덱스, [2]: mid에 위치한지
    curHand["left"] = {-1, 3, NOT_MID};

    for (int i = 0; i < numbers.size(); i++)
    {
        int cur = numbers[i];
        string selectHand;
        int idx;
        auto leftIdx = find(left.begin(), left.end(), cur);
        auto rightIdx = find(right.begin(), right.end(), cur);

        if (leftIdx != left.end())
        {
            selectHand = "left";
            curHand[selectHand][2] = NOT_MID;
            idx = leftIdx - left.begin();
        }
        else if (rightIdx != right.end())
        {
            selectHand = "right";
            curHand[selectHand][2] = NOT_MID;
            idx = rightIdx - right.begin();
        }
        else // cur: 2, 5, 8, 0
        {
            int curIdx = find(mid.begin(), mid.end(), cur) - mid.begin();
            int distanceR = abs(curHand["right"][1] - curIdx);
            int distanceL = abs(curHand["left"][1] - curIdx);
            curHand["right"][2] == NOT_MID ? distanceR++ : NULL;
            curHand["left"][2] == NOT_MID ? distanceL++ : NULL;

            if (distanceR == distanceL)
            {
                selectHand = hand;
            }
            else if (distanceR < distanceL)
            {
                selectHand = "right";
            }
            else
            {
                selectHand = "left";
            }
            curHand[selectHand][2] = MID;
            idx = curIdx;
        };
        selectHand == "right" ? answer += "R" : answer += "L";
        curHand[selectHand][0] = cur;
        curHand[selectHand][1] = idx;
    }
    return answer;
}

int main()
{
    cout << solution({1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5}, "right") << endl;
}
