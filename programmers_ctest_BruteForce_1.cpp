#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
bool orm(int a, int b) {
    return a > b;
}
vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> p1({ 1,2,3,4,5 }), p2({ 2,1,2,3,2,4,2,5 }), p3({ 3,3,1,1,2,2,4,4,5,5 });
    vector<int> scores;
    vector<int> result;
    int f = 0, s = 0, t = 0;

    scores.push_back(0); scores.push_back(0); scores.push_back(0);

    for (int i = 0; i < answers.size(); i++) {
        f = i % 5; s = i % 8; t = i % 10;
        if (answers[i] == p1[f])scores[0]++;
        if (answers[i] == p2[s])scores[1]++;
        if (answers[i] == p3[t])scores[2]++;
    }
    result = scores; 
    sort(scores.begin(), scores.end(),orm); //높은 점수순으로(내림차순) 정렬
      
    for (int j = 0; j < result.size(); j++) {
        if (scores[0] == result[j])answer.push_back(j + 1); //result에서 최고점과 같은 애를 answer에 추가 시킨다.
    }
    sort(answer.begin(), answer.end()); //동점자가 있다면 오름차순으로 정렬

    return answer;
}