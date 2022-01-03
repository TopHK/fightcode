#include<iostream>
using namespace std;

void ReplaceBnk(char str[], int length) {
    int bnk_count = 0;
    int original_length = strlen(str);
    for (int i = 0; i < original_length; ++i) {
        if (str[i] == ' ') {
            ++bnk_count;
        }
    }
    int current_length = original_length + 2 * bnk_count;
    if (current_length > length) {
        cout << "string length is not enough!" << endl;
        return;
    }
    int i = original_length - 1;
    int j = current_length - 1;
    while (i >= 0) {
       if (str[i] != ' ') {
           str[j--] = str[i];
       } else {
           str[j--] = '0';
           str[j--] = '2';
           str[j--] = '%';
       }
       --i;
    }
}

int main() {
    char str[18] = {'W', 'e', ' ', 'a', 'r', 'e', ' ', 'h', 'a', 'p', 'p', 'y', '.'};
    cout << str << " " << strlen(str) << endl;
    ReplaceBnk(str, 18);
    cout << str << " " << strlen(str) << endl;
    return 0;
}

