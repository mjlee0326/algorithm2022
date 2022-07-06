#include <iostream>
#include <string>
#include <vector>

#define PLUS 1
#define MINUS -1

using namespace std;

int answer = 0;

void dfs(vector<int> numbers, int sum, int target, int type, int index)
{
    if (index >= 0)
    {
        sum += (numbers[index] * type);
        if ((index + 1) == numbers.size())
        {
            if (sum == target)
                answer++;

            return;
        }
    }
    dfs(numbers, sum, target, PLUS, index + 1);
    dfs(numbers, sum, target, MINUS, index + 1);

    return;
}

int solution(vector<int> numbers, int target)
{
    dfs(numbers, 0, target, 0, -1);
    return answer;
}

int main()
{
    cout << "hello" << endl;
    cout << solution({1, 1, 1, 1, 1}, 3) << endl;
    answer = 0;
    cout << solution({4, 1, 2, 1}, 2) << endl;
}