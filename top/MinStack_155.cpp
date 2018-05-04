/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
Example:
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> Returns -3.
minStack.pop();
minStack.top();      --> Returns 0.
minStack.getMin();   --> Returns -2.
*/

class MinStack
{
private:
    stack<int> st1,st2;
public:
    /** initialize your data structure here. */
    MinStack()
    {

    }

    void push(int x)
    {
        st1.push(x);
        if(st2.empty()) st2.push(x);
        else if(x >= st2.top()) st2.push(st2.top());
        else st2.push(x);
    }

    void pop()
    {
        st1.pop();
        st2.pop();
    }

    int top()
    {
        return st1.top();
    }

    int getMin()
    {
        return st2.top();
    }
};
