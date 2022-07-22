#include<bits/stdc++.h>
using namespace std;
class MyStack {
public:
    deque<int> dq;
    MyStack() {
        
    }
    void push(int x) {
        dq.push_back(x);
    }
    int pop() {
        int val=dq.back();
        dq.pop_back();
        return val;
    }
    int top() {
        return dq.back();
    }
    bool empty() {
        return dq.empty();
    }
};
class MyQueue {
    public:
        deque<int> dq1;
        MyQueue() {
            
        }
        void push(int x) {
            dq1.push_back(x);
        }
        int pop() {
            int val=dq1.front();
            dq1.pop_front();
            return val;
        }
        int peek() {
            return dq1.front();
        }
        bool empty() {
            return dq1.empty();
        }
};
int main(){
    MyStack myStack;
    myStack.push(1);
    myStack.push(2);
    cout<<myStack.top()<<" ";
    cout<<myStack.pop()<<" "; 
    cout<<myStack.top()<<" ";
    cout<<myStack.empty()<<endl;
    MyQueue myQueue;
    myQueue.push(1);
    myQueue.push(2); 
    cout<<myQueue.peek()<<" "; 
    cout<<myQueue.pop()<<" "; 
    cout<<myQueue.empty()<<endl;
}