#include <iostream>
#include <vector>
using namespace std;

class Truck {
public:
    Truck(int a) {
        w = a;
    }
    int w=0;
    int p =0;
};
int solution(int bridge_length, int weight, vector<Truck> truck_weights) {
    int answer = 0;
    int count = 0;
    int current_weight = 0;
    vector<Truck> truck;
    while (true) { 
        count += 1;
            if ((!truck_weights.empty()) && (current_weight + truck_weights.front().w <= weight)) { //다음 트럭 들여도 감당무게 초과 안하면 다리에 트럭추가
                current_weight += truck_weights.front().w;
                truck.push_back(truck_weights.front());
                truck_weights.erase(truck_weights.begin());  
            }          
            
            for (int i = 0; i < truck.size(); i++) { //다리를 건너는 중이던 트럭들 전진
                truck[i].p += 1;
            }

            if (truck.front().p > bridge_length) { //다리 다 건넜으면 추방
                current_weight -= truck.front().w;
                truck.erase(truck.begin());
                if ((!truck_weights.empty()) && (current_weight + truck_weights.front().w <= weight)) { //다 건넌 트럭 추방과 동시에 새로운 트럭 들임
                    current_weight += truck_weights.front().w;
                    truck.push_back(truck_weights.front());
                    truck_weights.erase(truck_weights.begin());
                    truck.back().p += 1;
                }
            }

            
            if ((truck.empty())&&(truck_weights.empty())&&current_weight==0)break;
     }
    answer = count;
    return answer;
}
int main() {
    vector<Truck> tv;
    Truck t1(7); Truck t2(4); Truck t3(5); Truck t4(6);
    tv.push_back(t1); tv.push_back(t2); tv.push_back(t3); tv.push_back(t4);
    int num = 0;
    num = solution(3, 10, tv);
    cout << num;
    return 0;
}