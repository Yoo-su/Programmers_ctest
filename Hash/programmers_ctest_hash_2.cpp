bool solution(vector<string> phone_book) {
    bool answer = true;
    string tmp = "";

    for (int i = 1; i < phone_book.size(); i++) {
        if (phone_book[i].length()<phone_book[0].length()) { //swap
            tmp=phone_book[0];
            phone_book[0] = phone_book[i];
            phone_book[i] = tmp;
        }
    }

    string s = phone_book[0];
    for (int j = 1; j < phone_book.size(); j++) {
        if (phone_book[j].find(s) == 0) {
            answer = false;
            break;
        }
    }
    return answer;
}