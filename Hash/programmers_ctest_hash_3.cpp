#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 0;
    int count = 0;
    vector<string> kind;
    multimap<string, string> mm;
    for (int i = 0; i < clothes.size(); i++) { //multi map에 종류별로 넣어준다
        mm.insert(pair<string, string>(clothes[i][1], clothes[i][0]));
        auto it = find(kind.begin(), kind.end(), clothes[i][1]);
        if (it == kind.end())kind.push_back(clothes[i][1]);
    }
    
    int test = 1;
    for (int i = 0; i < kind.size(); i++) {
        test = test * (mm.count(kind[i])+1);
   }

    test = test - 1;
    answer = test;
    return answer;
}