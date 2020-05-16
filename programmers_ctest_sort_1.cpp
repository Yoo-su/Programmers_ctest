#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> copy;
    for (int i = 0; i < commands.size(); i++) {
        for (int j = commands[i][0] - 1; j <= commands[i][1] - 1; j++) {
            copy.push_back(array[j]);
        }
        sort(copy.begin(), copy.end());
        answer.push_back(copy[commands[i][2] - 1]);
        copy.clear();
    }
    return answer;
}
