#include<bits/stdc++.h>
using namespace std;
class StockSpanner {
public:
    stack<pair<int,int>> st;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int cnt=0;
        while(!st.empty() && st.top().first<=price){
            cnt+=st.top().second;
            st.pop();
        }
        st.push({price,cnt+1});
        return cnt+1;
    }
};

int main(){
    int n;
    cin>>n;
    int prices[n];
    for(int i=0;i<n;i++){
        cin>>prices[i];
    }
    StockSpanner obj;
    for(int i=0;i<n;i++){
        cout<<obj.next(prices[i])<<" ";
    }
}