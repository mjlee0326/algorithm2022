#include <iostream>
#include <vector>
using namespace std;

const int N = 10;
const int R = 5;
int list[11] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
vector<int> choose; // 선택한 원소를 보관

int cnt = 0;
void Combination(int index, int level)
{
    if (level == R)
    {
        // 선택한 R 개의 원소를 출력
        // for (auto &u : choose)
        // {
        //     cout << u << " ";
        // }
        // cout << "\n";
        cnt++;
        return;
    }

    // for문
    for (int i = index; i <= N; i++)
    {
        choose.push_back(list[i]);     // i 번째 원소를 선택(추가)
        Combination(i + 1, level + 1); // 다음 for 문으로 들어가는 역할
        choose.pop_back();             // 넣었던 i 번째 원소를 제거
    }
}

int main()
{
    Combination(1, 0);
    cout << cnt << endl;
    return 0;
}