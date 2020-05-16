int solution(vector<int> priorities, int location) {
    int answer = 0;
    int count = 0;
    int point = 0;
    int overcheck = priorities.size();
    bool check = false;
    vector<int> turn;
    vector<int> result;
    vector<int> resultturn;
    for (int i = 0; i < priorities.size(); i++) {
        turn.push_back(i);
    }
    point = turn[location];
    while (true) {
        check = false;
        for (int i = 1; i < priorities.size(); i++) {
            if (priorities[i] > priorities.front()) { //첫번째 아이보다 더 중요한 아이가 있으면
                check = true;
                break;
            }
        }

        if (check) { //더 중요한 아이가 있는게 확인되었으면 순서 뒤로 보내버림
            priorities.push_back(priorities.front());
            turn.push_back(turn.front());
            priorities.erase(priorities.begin());
            turn.erase(turn.begin());
        }
        else { //더 중요한 아이가 없으면
            result.push_back(priorities.front());
            resultturn.push_back(turn.front());
            priorities.erase(priorities.begin());
            turn.erase(turn.begin());
        }

        if (result.size() == overcheck)break;
    }
    for (int i = 0; i < resultturn.size(); i++) { //중요순위에 따라 정렬된 결과 vector에서 찾으려는 아이의 순서 파악
        if (resultturn[i] == point) {
            answer = i + 1;
            break;
        }
    }

    return answer;
}