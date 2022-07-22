#include<bits/stdc++.h>
using namespace std;
class MyQueue {
    public:
        stack<int> s1;
        MyQueue() {
            
        }
        void push(int x) {
            stack<int> temp;
            while(s1.empty()==false){
                temp.push(s1.top());
                s1.pop();
            }
            s1.push(x);
            while(temp.empty()==false){
                s1.push(temp.top());
                temp.pop();
            }
        }
        int pop() {
            int val=s1.top();
            s1.pop();
            return val;
        }
        int peek() {
            return s1.top();
        }
        bool empty() {
            return s1.empty();
        }
};
int main(){
    MyQueue myQueue;
    myQueue.push(1);
    myQueue.push(2); 
    cout<<myQueue.peek()<<" "; 
    cout<<myQueue.pop()<<" "; 
    cout<<myQueue.empty()<<endl;;
}