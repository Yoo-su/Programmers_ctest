#include <iostream>
#include <vector>
using namespace std;

vector<int> solution(vector<int> heights) {
    vector<int> answer;
    for (int i = 0; i < heights.size(); i++) {
        bool y = false;
        for (int j = i - 1; j >= 0;j--) {
            if (heights[j] > heights[i]) {
                answer.push_back(j+1);
                y = true; 
                break;
            }
        }
        if (y == false)answer.push_back(0);
   }
    return answer;
}
int main() {
    vector<int> h;
    vector<int> test;
    h.push_back(6); 
    h.push_back(9); 
    h.push_back(5); 
    h.push_back(7);
    h.push_back(4);
    test = solution(h);
    for (int i = 0; i < test.size(); i++) {
        cout << test[i]<<" ";
    }
    return 0;
}