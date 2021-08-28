vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<bool> status;
    int count = 0;
    for (int i = 0; i < progresses.size(); i++) {
        status.push_back(false);
    }
    while (!progresses.empty()) {
        count = 0;
        for (int i = 0; i < progresses.size(); i++) {
            if (progresses[i] < 100)progresses[i] += speeds[i]; // 작업 진행
            if (progresses[i] >= 100)status[i] = true;
        }
        if (status.front() == true) {
            for (int a = 0; a < progresses.size(); a++) {
                if (status[a] == true)count += 1;
                else break;
            }
            answer.push_back(count);
        }
        while (true) { //추가된 기능 제거  
            if (status.front() == false|| progresses.empty())break;
            else {
                progresses.erase(progresses.begin());
                speeds.erase(speeds.begin());
                status.erase(status.begin());
            }
            if (status.empty())break;
        }
    }
    return answer;
}