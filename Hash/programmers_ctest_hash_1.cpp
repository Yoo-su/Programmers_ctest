#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";

    unordered_map<string, int> ht;
    for (string name : participant) {
        ht[name]++;
    }
    for (string name : completion) {
        ht[name]--;
    }
    for (string name : participant) {
        if (ht[name] > 0) {
            answer = name;
            break;
        }
    }
    return answer;
}