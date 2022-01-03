#include<iostream>
#include<stack>
using namespace std;

template <typename T>
class Queue {
private:
    stack<T> st1, st2;
public:
    void AppendTail(const T& val) {
        st1.push(val);
    }
    T DeleteHead() {
        if (st2.empty()) {
            while(!st1.empty()) {
                st2.push(st1.top());
                st1.pop();
            }
        }
        T top_val = st2.top();
        st2.pop();
        return top_val;
    }
};

