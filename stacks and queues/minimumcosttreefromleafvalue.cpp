#include<bits/stdc++.h>
using namespace std;
int mctFromLeafValues(vector<int>& arr) {
    int res=0;
    stack<int> st;
    st.push(INT_MAX);
    for(int x:arr){
        while(st.top()<=x){
            int mid=st.top();
            st.pop();
            res+=mid*min(st.top(),x);
        }
        st.push(x);
    }
    while(st.size()>2){
        int temp=st.top();
        st.pop();
        res+=temp*st.top();
    }
    return res;
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int res=mctFromLeafValues(arr);
    cout<<res<<endl;
}