#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main()
{
    vector<vector<string>> str{{"ICN", "B"}, {"B", "ICN"}, {"ICN", "A"}, {"A", "D"}, {"D", "A"}};
    sort(str.begin(), str.end());
    for (const auto &row : str)
    {

        for (const auto &i : row)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}