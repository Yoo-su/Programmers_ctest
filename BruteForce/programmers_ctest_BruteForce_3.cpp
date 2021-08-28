#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> baseball) {
    int answer = 0;
    int x = 0, y = 0;
    bool check = false;
    bool check2 = false;
    string tmp = "";
    string tmp2 = "";
    char tmp3;
    for (int a = 123; a <= 987; a++) {
        check = false;
        check2 = false;
        tmp = to_string(a);
        if (tmp.find('0') != string::npos)continue; //0들어있으면 패스

        for (int i = 0; i < tmp.length(); i++) {
            tmp3 = tmp[i];
            for (int j = 0; j < tmp.length(); j++) {
                if (j == i)continue;
                if (tmp[j] == tmp3) {
                    check2 = true;
                    break;
                }
            }
        }
        if (check2)continue;

        for (int b = 0; b < baseball.size(); b++) {
            x = 0; y = 0;
            tmp2 = to_string(baseball[b][0]);

            for (int i = 0; i < tmp.length(); i++) {
                if ((char)tmp.at(i) == (char)tmp2.at(i))x++;   //스트라이크면 x++
                else if (((char)tmp.at(i)!=(char)tmp2.at(i))&&(tmp.find(tmp2.at(i)) != string::npos))y++;   //볼이면 y++
            }
            if (x == baseball[b][1] && y == baseball[b][2])continue;
            else {
                check = true;
                break;
            }
        }
        if (!check)answer++;
    }
    return answer;
}

int main() {

    return 0;
}