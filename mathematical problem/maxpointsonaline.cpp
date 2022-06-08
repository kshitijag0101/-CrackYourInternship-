#include<bits/stdc++.h>
using namespace std;
int maxPoints(vector<vector<int>>& points) {
    int res=0;
    int n=points.size();
    sort(points.begin(),points.end());
    for(int i=0;i<n;i++){
        map<pair<int,int>,int> mp;
        for(int j=0;j<n;j++){
            if(i==j) continue;
            int num=points[j][1]-points[i][1];
            int den=points[j][0]-points[i][0];
            int hcf=__gcd(num,den);
            if(hcf==0) hcf=1;
            num/=hcf;
            den/=hcf;
            mp[{num,den}]++;
        }
        for(auto x:mp){
            res=max(res,x.second);
        }
    }
    return res+1;
}
int main(){
    int r;
    cin>>r;
    vector<vector<int>> points(r,vector<int>(2,0)); 
    for(int i=0;i<r;i++){
        for(int j=0;j<2;j++){
            cin>>points[i][j];
        }
    }
    int res=maxPoints(points);
    cout<<res<<endl;
}