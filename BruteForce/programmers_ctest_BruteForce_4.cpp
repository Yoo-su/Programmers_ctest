#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int brown, int red) {
    vector<int> answer;
    int a = 0, b = 0;

    for (int i=1; i <=2000000; i++) {
        for (int j = 1; j <= 2000000; j++) {
            if(j>i)break;
            if (i * j == red && i>=j) { //곱해서 red가 나오는 경우 중 i>=j 이고,
                if ((i+i+j+j+4) == brown) { //둘레 합이 brown이 되는 경우면 ..
                    answer.push_back(i + 2);
                    answer.push_back(j + 2);
                    return answer;
                }
            }
        }
    }
}