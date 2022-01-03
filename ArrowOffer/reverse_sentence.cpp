#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

void ReverseSentence(string& sentence) {
    reverse(sentence.begin(), sentence.end());
    int start_pos = -1;
    for (int i = 0; i < sentence.size(); ++i) {
        if (sentence[i] != ' ' && (i == 0 || sentence[i-1] == ' ')) {
            start_pos = i;
        }
        if (sentence[i] == ' ' && i !=0 && sentence[i-1] != ' ') {
            reverse(sentence.begin() + start_pos, sentence.begin() + i);
        }
    }
}

int main() {
    string sentence = "  I am an student.  ";
    ReverseSentence(sentence);
    cout << sentence << endl;
    return 0;
}