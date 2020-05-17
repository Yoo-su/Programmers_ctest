#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> status;
    for (int i = 0; i < n; i++)status.push_back(1);

    for (int i = 0; i < lost.size(); i++) { //잃어버린애 해당 인덱스 값 false로 변경
        status[lost[i] - 1] -=1;
    }

    for (int i = 0; i < reserve.size(); i++) {
        status[reserve[i] - 1] +=1;
    }

    for (int i = 0; i < status.size(); i++) {
        if (i == 0 && status[i] == 0) {
            if (status[1] == 2) {
                status[i] += 1;
                status[1] -= 1;
                continue;
            }
        }
        else if (i == status.size()-1 && status[i]==0) {
            if (status[i - 1] == 2) {
                status[i] += 1;
                status[i - 1] -= 1;
                break;
            }
        }
        else if (i != 0 && i!=status.size()-1 && status[i] == 0) {
            if (status[i - 1] == 2) {
                status[i] += 1;
                status[i - 1] -= 1;
                continue;
            }
            else if (status[i - 1] != 2 && status[i + 1] == 2) {
                status[i] += 1;
                status[i + 1] -= 1;
                continue;
            }
        }
    }

    for (int i = 0; i < status.size(); i++)if (status[i] == 1||status[i]==2)answer++;
    return answer;
}