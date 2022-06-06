#include<bits/stdc++.h>
using namespace std;
int maxHist(vector<int> row){
    stack<int> res;
    int top=0,area=0,maxarea=0;
    int i=0;
    while(i<row.size()){
        if(res.empty() || row[res.top()]<=row[i]){
            res.push(i++);
        }
        else{
            top=row[res.top()];
            res.pop();
            area=top*i;
            if(!res.empty()){
                area=top*(i-res.top()-1);
            }
            maxarea=max(area,maxarea);
        }
    }
    while(!res.empty()){
        top=row[res.top()];
        res.pop();
        area=top*i;
        if(!res.empty()){
            area=top*(i-res.top()-1);
        }
        maxarea=max(area,maxarea);
    }
    return maxarea;
}
int maxrectangle(vector<vector<int>>& a,int r,int c){
    int res=maxHist(a[0]);
    for(int i=1;i<r;i++){
        for(int j=0;j<c;j++){
            if(a[i][j]) a[i][j]+=a[i-1][j];
        }
        res=max(res,maxHist(a[i]));
    }
    return res;
}
int main(){
    int r,c,x;
    cin>>r>>c;
    vector<vector<int>> a;
    for(int i=0;i<r;i++){
        vector<int> b;
        for(int j=0;j<c;j++){
            cin>>x;
            b.push_back(x);
        }
        a.push_back(b);
    }
    int res=maxrectangle(a,r,c);
    cout<<"Max area rectangle = "<<res<<endl;
}