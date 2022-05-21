#include<bits/stdc++.h>
using namespace std;
struct cmp{
    bool operator()(vector<int>& p1,vector<int>& p2){
        return p1[1]-p1[0]<p2[1]-p2[0];
    }
};
int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
    int res=INT_MIN;
    priority_queue<vector<int>,vector<vector<int>>,cmp> pq;
    pq.push(points[0]);
    for(int i=1;i<points.size();i++){
        while(pq.size()>0 && points[i][0]-pq.top()[0]>k){
            pq.pop();
        }
        if(pq.size()>0){
            res=max(res,points[i][1]+pq.top()[1]+points[i][0]-pq.top()[0]);
        }
        pq.push(points[i]);
    }
    return res;
}
int main(){
    int r,c,x;
    cin>>r>>c;
    vector<vector<int>> points;
    for(int i=0;i<r;i++){
        vector<int> mat;
        for(int j=0;j<c;j++){
            cin>>x;
            mat.push_back(x);
        }
        points.push_back(mat);
    }
    int k;
    cin>>k;
    int res=findMaxValueOfEquation(points,k);
    cout<<res<<endl;
}