#include <iostream>
#include <cstdlib>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string s)
{
    stack<char> ss;
    ss.push(s[0]);
    for (int i = 1; i < s.length(); i++) {
        if (!ss.empty() && ss.top() ==s[i]) {
            ss.pop();
        }
        else ss.push(s[i]);
    }

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "Hello Cpp" << endl;
    return ss.empty() ? 1 : 0;
}