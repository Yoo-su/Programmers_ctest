#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string dartResult) {
    int answer = 0;
    string tmp = "";
    vector<int> numbs;

    for (int i = 0; i < dartResult.length(); i++) {
        if ((char)dartResult[i] == 'S') {
            numbs.push_back(atoi(tmp.c_str()));
            tmp = "";
            continue;
        }

        else if ((char)dartResult[i] == 'D') {
            numbs.push_back(atoi(tmp.c_str())*atoi(tmp.c_str()));
            tmp = "";
            continue;
        }

        else if ((char)dartResult[i] == 'T') {
            numbs.push_back(atoi(tmp.c_str()) * atoi(tmp.c_str())*atoi(tmp.c_str()));
            tmp = "";
            continue;
        }

        else if ((char)dartResult[i] == '*') {
            if (numbs.size() == 1)numbs[0] *= 2;
            else if (numbs.size() == 2) {
                numbs[0] *= 2; numbs[1] *= 2;
            }
            else if (numbs.size() == 3) {
                numbs[1] *= 2; numbs[2] *= 2;
            }
            continue;
        }

        else if ((char)dartResult[i] == '#') {
            if (numbs.size() == 1)numbs[0]=-numbs[0];
            else if (numbs.size() == 2) {
                numbs[1]=-numbs[1];
            }
            else if (numbs.size() == 3) {
                numbs[2]=-numbs[2];
            }
            continue;
        }
        else {
            tmp += dartResult[i];
        }
    }
    for (int j = 0; j < numbs.size(); j++)answer += numbs[j];
    return answer;
}