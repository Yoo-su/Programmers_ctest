#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
bool ssort(string a, string b) {
    return a + b > b + a;
}
string solution(vector<int> numbers) {
    string answer = "";
    vector<string> test;
    for (int i = 0; i < numbers.size(); i++) {
        test.push_back(to_string(numbers[i]));
    }

    sort(test.begin(), test.end(), ssort);

    for (int i = 0; i <test.size(); i++) {
        answer += test[i];
    }

    if ((char&)answer.at(0) == '0')answer = "0";

    return answer;
}