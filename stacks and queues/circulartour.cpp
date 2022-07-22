#include<bits/stdc++.h>
using namespace std;
struct petrolPump{
    int petrol;
    int distance;
};
int tour(petrolPump p[],int n){
    int start=0,curr_pet=0,prev_pet=0;
    for(int i=0;i<n;i++){
        curr_pet+=(p[i].petrol-p[i].distance);
        if(curr_pet<0){
            start=i+1;
            prev_pet+=curr_pet;
            curr_pet=0;
        }
    }
    return ((curr_pet+=prev_pet)>=0)? (start):-1;
}
int main(){
    int n;
    cin>>n;
    petrolPump p[n];
    for(int i=0;i<n;i++){
        cin>>p[i].petrol;
    }
    for(int i=0;i<n;i++){
        cin>>p[i].distance;
    }
    int res=tour(p,n);
    cout<<res<<endl;
}