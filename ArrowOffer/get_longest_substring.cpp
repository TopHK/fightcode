#include<iostream>
#include<string>
using namespace std;

int GetLongestSubstring(const string& str) {
    if (str.size() <= 1) {
        return str.size();
    }
    int max_len = 1;
    int cur_len = 1;
    for (int i = 1; i < str.size(); ++i) {
        int start_pos = i - cur_len;
        string sub_str = str.substr(start_pos, cur_len);
        int pos = sub_str.find_last_of(str[i]);

        if (pos == string::npos) {
            ++cur_len;
        } else {
            cur_len = i - (start_pos + pos);
        }
//        cout << i << " " << start_pos << " " << pos << " " << cur_len << endl;
        if (cur_len > max_len) {
            max_len = cur_len;
        }
    }
    return max_len;
}

int main(){
    string str = "arabcacfr";
    cout << GetLongestSubstring(str) << endl;
    return 0;
}