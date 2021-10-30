#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

int divCount = 0;
map<pair<int, int>, bool> visited;
vector<vector<int>> copypic;

void dfs(int x, int y, int m, int n, int nodeVal) {
    if (copypic[x][y] != nodeVal) {
        return;
    }

    if (visited[make_pair(x, y)] == true) {
        return;
    }

    //아직 방문하지 않은 위치고, nodeVal과 같은 값의 영역이면..
    divCount += 1;
    visited[make_pair(x,y)] = true;
    int dx[4] = { x, x, x - 1, x + 1 };
    int dy[4] = { y - 1, y + 1, y, y };

    for (int i = 0; i < 4; i++) {
        if ((dx[i]>=0&&dx[i]<n) && (dy[i]>=0 && dy[i] < m)) {
            dfs(dx[i], dy[i], m, n, nodeVal);
        }
    }
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    copypic = picture;

    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;

    //visited 초기화
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            visited[make_pair(i, j)] = false;
        }
    }

    vector<int> counts;
    int total = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (visited[make_pair(i,j)] == false && picture[i][j] != 0) {
                dfs(i, j, m, n, picture[i][j]);
                counts.push_back(divCount);
                divCount = 0;
                total += 1;
            }
        }
    }
    int maxVal = *max_element(counts.begin(), counts.end());
    answer[0]=total;
    answer[1]=maxVal;

    return answer;
}