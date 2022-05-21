#include<bits/stdc++.h>
using namespace std;
int largestRectangleArea(vector<int>& heights) {
    stack<int> s;
    int res=0;
    int tp,curr;
    for(int i=0;i<heights.size();i++){
        while(s.empty()==false && heights[s.top()]>heights[i]){
            tp=s.top();
            s.pop();
            curr=heights[tp]*(s.empty()?i:i-s.top()-1);
            res=max(res,curr);
        }
        s.push(i);
    }
    while(s.empty()==false){
        tp=s.top();
        s.pop();
        curr=heights[tp]*(s.empty()?heights.size():heights.size()-s.top()-1);
        res=max(res,curr);
    }
    return res;
}
int main(){
    int n,x;
    cin>>n;
    vector<int> heights;
    for(int i=0;i<=n;i++){
        cin>>x;
        heights.push_back(x);
    }
    int res=largestRectangleArea(heights);
    cout<<res<<endl;
}