#include<bits/stdc++.h>
using namespace std;
int maxProfit(vector<int>& prices) {
    int buy=prices[0],profit=0;
    for(int i=1;i<prices.size();i++){
        if(buy>prices[i]){
            buy=prices[i];
        }
        else if(prices[i]-buy>profit){
            profit=prices[i]-buy;
        }
    }
    return profit;
}
int main(){
    int n,x;
    cin>>n;
    vector<int> prices;
    for(int i=0;i<n;i++){
        cin>>x;
        prices.push_back(x);
    }
    int res=maxProfit(prices);
    cout<<res<<endl;
}
