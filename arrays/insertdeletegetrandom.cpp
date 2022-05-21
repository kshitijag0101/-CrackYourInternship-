#include<bits/stdc++.h>
using namespace std;
class RandomizedCollection {
public:
    unordered_map<int,set<int>> mp;
    vector<int> v;
    int size=0;
    RandomizedCollection() {
        v.resize(100005,-1);
        size=0;
    }
    bool insert(int val) {
        bool flag;
        if(mp.count(val)){
            flag=false;
        }
        else{
            flag=true;
        }
        mp[val].insert(size);
        v[size]=val;
        size++;
        return flag;
    }
    bool remove(int val) {
        if(mp.count(val)==0){
            return false;
        }
        auto it=mp[val].end();
        it--;
        int x=*it;
        mp[val].erase(it);
        if(mp[val].size()==0){
            mp.erase(val);
        }
        if(size==1 || x==size-1){
            size--;
            v[x]=-1;
            return true;
        }
        v[x]=v[size-1];
        it=mp[v[size-1]].end();
        it--;
        mp[v[size-1]].erase(it);
        mp[v[size-1]].insert(x);
        v[size-1]=-1;
        size--;
        return true;
    }
    int getRandom() {
        return v[rand()%size];
    }
};
int main(){
    RandomizedCollection* obj=new RandomizedCollection();
    bool c=obj->insert(1);
    cout<<c<<" ";
    c=obj->insert(1);
    cout<<c<<" ";
    c=obj->insert(2);
    cout<<c<<" ";
    int c1=obj->getRandom();
    cout<<c1;
    c=obj->remove(1);
    cout<<c<<" ";
    c1=obj->getRandom();
    cout<<c1<<endl;
}