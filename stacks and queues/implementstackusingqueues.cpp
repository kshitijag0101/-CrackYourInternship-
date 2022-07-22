#include<bits/stdc++.h>
using namespace std;
class MyStack {
public:
    queue<int> q;
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
        for(int i=1;i<q.size();i++){
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int val=q.front();
        q.pop();
        return val;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};
int main(){
    MyStack myStack;
    myStack.push(1);
    myStack.push(2);
    cout<<myStack.top()<<" ";
    cout<<myStack.pop()<<" "; 
    cout<<myStack.top()<<" ";
    cout<<myStack.empty()<<" ";
}