#include <iostream>
#include <string>
#include <vector>

using namespace std;
int answer = 0;

void dfs(vector<int> num, int targ, int sum, int index) {
    if (index == num.size()) { //카운트 조건: 벡터를 다 거쳤고, 합계가 타겟값과 같으면..
        if (sum == targ)  answer++;
            return;     
    }
     
    dfs(num, targ, sum+num[index], index + 1);  //벡터 요소를 더해보고 빼보는 것
    dfs(num, targ, sum - num[index], index + 1);
}

int solution(vector<int> numbers, int target) {
    dfs(numbers, target, 0, 0);
    return answer;
}