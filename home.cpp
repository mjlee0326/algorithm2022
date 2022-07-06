#include <iostream>
#include <vector>
#include <typeinfo>
#include <string>
#include <map>

using namespace std;

vector<string> solution(string path)
{
    vector<string> answer;
    map<char, int> mapDirection;
    mapDirection['E'] = 0;
    mapDirection['N'] = 1;
    mapDirection['W'] = 2;
    mapDirection['S'] = 3;
    char curPath = path[0];
    int distance = 100;
    int time = 0;
    int cnt = 1;
    int x, y;
    string msg = "Time : Go straight m and turn";

    for (int i = 1; i < path.size(); i++)
    {
        if (curPath == path[i])
        {
            distance += 100;
            cnt++;
        }
        else
        {
            if (distance > 500)
            {
                // cout << "distance: " << 500 << endl;
                // cout << "time: " << time + (distance - 500) / 100 << endl;
                x = time + (distance - 500) / 100;
                y = 500;
            }
            else
            {
                // cout << "distance: " << distance << endl;
                // cout << "time: " << time << endl;
                x = time;
                y = distance;
            }
            // cout << "cnt: "<< cnt << endl;
            // answer.push_back("Time")

            msg.insert(5, to_string(x));
            msg.insert(20, to_string(y));
            if ((curPath == 'S' && path[i] == 'E'))
            {
                msg.insert(msg.length(), " left");
            }
            else if (curPath == 'E' && path[i] == 'S')
            {
                msg.insert(msg.length(), " right");
            }
            else if (mapDirection[curPath] < mapDirection[path[i]])
            {

                msg.insert(msg.length(), " left");
            }
            else
            {

                msg.insert(msg.length(), " right");
            }
            cout << msg << endl;
            answer.push_back(msg);
            curPath = path[i];
            distance = 100;
            time += cnt;
            cnt = 1;
            msg = "Time : Go straight m and turn";
        }
    }

    return answer;
}

int main()
{
    solution("EEESEEEEEENNNN");
    cout << endl;
    solution("SSSSSSWWWNNNNNN");
}