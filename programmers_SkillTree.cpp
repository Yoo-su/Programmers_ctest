#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    string tmp = "";
    int answer = 0;
    for (int i = 0; i < skill_trees.size(); i++) {
        tmp = "";
        for (int j = 0; j < skill_trees[i].length(); j++) {
            if (skill.find(skill_trees[i][j]) != string::npos) {
                tmp += skill_trees[i][j];
            }
        }
        if (skill.find(tmp) ==0)answer++;
    }

    return answer;
}