#include<iostream>
#include<string>
using namespace std;

void PermutationCore(string& str, int index) {
    if (index >= str.size()) {
        cout << str << " ";
        return;
    }
    for (int i = index; i < str.size(); ++i) {
        char temp = str[index];
        str[index] = str[i];
        str[i] = temp;
        PermutationCore(str, index + 1);
        temp = str[index];
        str[index] = str[i];
        str[i] = temp;
    }
}

void Permutation(string& str){
    PermutationCore(str, 0);
}

int main() {
    string str = "abc";
    Permutation(str);
    return 0;
}