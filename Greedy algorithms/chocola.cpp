#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int m,n;
        cin>>m>>n;
        int hp[m-1],vp[n-1];
        for(int i=0;i<m-1;i++){
            cin>>hp[i];
        }
        for(int i=0;i<n-1;i++){
            cin>>vp[i];
        }
        sort(hp,hp+m-1,greater<int>());
        sort(vp,vp+n-1,greater<int>());
        int i=0,j=0,cost=0;
        int hcut=1,vcut=1;
        while(i<m-1 && j<n-1){
            if(vp[j]>=hp[i]){
                cost+=vp[j]*vcut;
                hcut++;j++;
            }
            else{
                cost+=hp[i]*hcut;
                vcut++;i++;
            }
        }
        while(i<m-1){
            cost+=hp[i]*hcut;
            vcut++;
            i++;
        }
        while(j<n-1){
            cost+=vp[j]*vcut;
            hcut++;
            j++;
        }
        cout<<cost<<endl;
    }
}