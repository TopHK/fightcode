#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

void ShiftSentence(string& sentence, int n) {
    if (sentence.size() <= 1 || (n % sentence.size()) == 0) {
        return;
    }
    n %= sentence.size();
    reverse(sentence.begin(), sentence.end());
    reverse(sentence.begin(), sentence.begin() + (sentence.size() - n));
    reverse(sentence.begin() + (sentence.size() -n), sentence.end());
}

int main() {
    string sentence("abcdefg");
    int n = 3;
    ShiftSentence(sentence, n);
    cout << sentence << endl;
    return 0;
}