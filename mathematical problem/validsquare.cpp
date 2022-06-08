#include<bits/stdc++.h>
using namespace std;
int getdistance(vector<int>& q1,vector<int>& q2){
    int d=((q1[0]-q2[0])*(q1[0]-q2[0]))+((q1[1]-q2[1])*(q1[1]-q2[1]));
    return d;
}
bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
    map<int,int> mp;
    vector<int> v;
    v.push_back(getdistance(p1,p2));
    v.push_back(getdistance(p2,p3));
    v.push_back(getdistance(p3,p4));
    v.push_back(getdistance(p1,p4));
    v.push_back(getdistance(p1,p3));
    v.push_back(getdistance(p2,p4));
    for(int i=0;i<v.size();i++){
        mp[v[i]]++;
    }
    for(auto it=mp.begin();it!=mp.end();it++){
        if(mp.size()==1 && it->first==0){
            return false;
        }
        if(it->first==0){
            return false;
        }
        if(it->second==4 || it->second==2 || it->second==6){
            continue;
        }
        return false;
    }
    if(mp.size()==1 || mp.size()==2){
        return true;
    }
    else{
        return false;
    }
}
int main(){
    vector<int> p1(2,0),p2(2,0),p3(2,0),p4(2,0);
    cin>>p1[0]>>p1[1];
    cin>>p2[0]>>p2[1];
    cin>>p3[0]>>p3[1];
    cin>>p4[0]>>p4[1];
    bool res=validSquare(p1,p2,p3,p4);
    if(res) cout<<"True"<<endl;
    else cout<<"False"<<endl;
}