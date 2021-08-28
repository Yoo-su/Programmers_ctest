#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    int count=0;
    int standard = 0;
    bool ant = false;
    for (int i = 0; i < prices.size(); i++) {
        if (i == prices.size()-1) {
            answer.push_back(0);
            break;
        }
        ant = false;
        standard = prices[i];
        count = 0;
        for (int j = i + 1; j < prices.size(); j++) {
            count += 1;
            if (prices[j] < standard) {
                answer.push_back(count);
                ant = true;
                break;
            }
        }
        if(!ant)answer.push_back(count);
    }
    return answer;
}