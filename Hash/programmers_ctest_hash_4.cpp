#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
bool great(pair<string, int> a, pair<string, int> b) {
    return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    vector<pair<string, int>> Vforsort;
    map<string, int> Gtotalplayed;
   
    for (int i = 0; i < genres.size(); i++) { //각 장르중 맥스재생수가 가장 큰 장르 찾기 위해 다더함
        Gtotalplayed[genres[i]] += plays[i];
    }

    for (auto au = Gtotalplayed.begin(); au != Gtotalplayed.end(); au++) { //맵을 벡터에 복사해준다 -> 정렬을 위함
        Vforsort.push_back(pair<string, int>(au->first, au->second));
    }

    sort(Vforsort.begin(), Vforsort.end(), great); //벡터 정렬

    for (auto au = Vforsort.begin(); au != Vforsort.end(); au++) { //장르벡터 내에서 같은 장르간 재생수가 높은 순으로 정렬하기
        int count = 0;
        int firstNum = 0, tempNum = 0,secondNum=0, firstSpot = 0, secondSpot = -1, tempSpot = 0;
        for (int i = 0; i < genres.size(); i++) {
            if (au->first == genres[i]) { //장르가 같으면
                if (firstNum == 0) { //첫 발견이면
                    firstNum = plays[i];
                    firstSpot = i;
                    count++;
                    continue;
                }

                if (count == 1) { //두번째 발견
                    if (plays[i] <= firstNum) {
                        secondSpot = i;
                        secondNum = plays[i];
                    }
                    else {
                        tempNum = firstNum;
                        firstNum = plays[i];
                        secondSpot = firstSpot;
                        firstSpot = i;
                        secondNum = tempNum;
                    }
                    count++;
                    continue;
                }

                if (plays[i] > firstNum) { //더 재생수가 높은 노래가 발견되면
                    tempNum = firstNum;
                    firstNum = plays[i];
                    secondSpot = firstSpot;
                    firstSpot = i;
                    secondNum = tempNum;
                }
                else if (plays[i] > secondNum) {
                    secondNum = plays[i];
                    secondSpot = i;
                }
                count++;
            }
        }
        answer.push_back(firstSpot);
        if (secondSpot != -1) {
            answer.push_back(secondSpot);
        }
    }
    return answer;
}