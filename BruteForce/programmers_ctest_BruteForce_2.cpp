#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int totalpn = 0;
bool ispn(int n) 
{
    int i = 0;
    int last = n / 2;   
    if (n <= 1)
    {
        return 0;
    }
    
    for (i = 2; i <= last; i++) 
    {
        if ((n % i) == 0) 
        {
            return 0; 
        }
    }
    return 1; 
}

int solution(string numbers) { 
    int answer = 0;
    string tmp="";
    bool check = false;
    vector<int> iv;
    vector<int> tmpv;
    vector<int> tmpv2;
    vector<int> pnlist;
    for (int i = 0; i < numbers.length(); i++) { //numbers 수 하나하나 정수벡터에 저장하는 과정
        iv.push_back(numbers.at(i) - '0');
    }

    for (int j = 1; j <= iv.size(); j++) { //정수벡터로부터 조합을 구하기 위해 1부터 size수만큼 조합을 구함
        for (int k = 0; k < j; k++)tmpv.push_back(1);
        for (int k = 0; k < iv.size() - j; k++)tmpv.push_back(0);
        sort(tmpv.begin(), tmpv.end());

        do { //nCr을 구한 후 그것에 대해서 다시 순열을 구함 
            for (int l = 0; l < tmpv.size(); l++) {
                if (tmpv[l] == 1)tmpv2.push_back(iv[l]);
            }

            sort(tmpv2.begin(), tmpv2.end());
           
            do { //순열 수들을 다 합한게 소수이면 카운트 증가
                tmp = "";
                for (int m = 0; m < tmpv2.size(); m++)tmp += to_string(tmpv2[m]);
                check = false;
                for (int a = 0; a < pnlist.size(); a++) { //중복 소수 체크를 위함
                    if (pnlist[a] == atoi(tmp.c_str())) {
                        check = true;
                        break;
                    }
                }
                if (check)continue;
                else pnlist.push_back(atoi(tmp.c_str()));

                if (tmp.at(0) - '0' == 0)continue;
                if (ispn(atoi(tmp.c_str()))) {
                    cout << tmp << endl;
                    totalpn++;
                }
            } while (next_permutation(tmpv2.begin(), tmpv2.end()));
            tmpv2.clear();
        } while (next_permutation(tmpv.begin(), tmpv.end()));

        tmpv.clear();
    }
    answer = totalpn;
    return answer;
}