#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    int index = 0; int point = k; int tmp = 0;
    int n = number.length() - k;
    vector<int> fin;
    
    while (n > 0) {
        for (int i = index; i <= number.length() - n; i++) {
            if (tmp < number[i] - '0') {
                tmp = number[i] - '0';
                index = i;
            }
        }
        n--; index++;
        fin.push_back(tmp);
        tmp = 0;
    }

    for (int i = 0; i < fin.size(); i++)answer += to_string(fin[i]);
    return answer;
}