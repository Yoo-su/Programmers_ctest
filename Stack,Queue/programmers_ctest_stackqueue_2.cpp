#include <iostream>
#include <vector>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int count = 0;
    int current_weight = 0;
    vector<int> truck_status;
    vector<int> ontheb;
    while (true) {
        count += 1;
        if ((!truck_weights.empty())&&(truck_weights.front() + current_weight <= weight)){ //다리에 추가 트럭 들일 수 있으면
            truck_status.push_back(0);
            ontheb.push_back(truck_weights.front());
            current_weight += truck_weights.front();
            truck_weights.erase(truck_weights.begin());
        }
        for (int i = 0; i < truck_status.size(); i++) { //도로 위 트럭 전진
            truck_status[i] += 1;
        }
        if (truck_status.front() > bridge_length) { //다리 다 건넜으면 지워버림
            current_weight -= ontheb.front();
            ontheb.erase(ontheb.begin());
            truck_status.erase(truck_status.begin());
            if ((!truck_weights.empty()) && (truck_weights.front() + current_weight <= weight)) {
                truck_status.push_back(1);
                ontheb.push_back(truck_weights.front());
                current_weight += truck_weights.front();
                truck_weights.erase(truck_weights.begin());
            }
        }
        if (ontheb.empty() && current_weight == 0)break;
    }
    answer = count;
    return answer;
}