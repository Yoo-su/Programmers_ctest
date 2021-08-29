#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
vector<bool> visited;
vector<vector<int>> tmp;
int c = 0;

void DFS(int a) { //깊이우선탐색 함수
    visited[a] = true; 
    for (int i = 0; i < tmp[a].size(); i++) { // 방문이 안된 곳이면서 1이면 DFS
        if (!visited[i]&&tmp[a][i]==1) {
            DFS(i);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    tmp = computers;
    for (int i = 0; i < n; i++)visited.push_back(false);

    for (int i = 0; i < computers.size(); i++) { //copmuters의 크기만큼 반복문 돌며 0부터 연결된 부분까지 쭉 돈다
        if (!visited[i]) { 
            c += 1;
            DFS(i);
        }
    }
    answer = c;
    return answer;
}