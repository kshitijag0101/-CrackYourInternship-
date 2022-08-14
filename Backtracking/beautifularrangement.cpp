class Solution {
public:
    int count(vector<int>& v,int n){
        if(n<=0) return 1;
        int res=0;
        for(int i=0;i<n;i++){
            if(v[i]%n==0 || n%v[i]==0){
                swap(v[i],v[n-1]);
                res+=count(v,n-1);
                swap(v[i],v[n-1]);
            }
        }
        return res;
    }
    int countArrangement(int n) {
        vector<int> v;
        for(int i=0;i<n;i++){
            v.push_back(i+1);
        }
        return count(v,n);
    }
};