class BIT{
public:
    int n;
    vector<int> arr;
    int getNext(int i){
        return i+(i&-i);
    }
    int getParent(int i){
        return i&(i-1);
    }
    BIT(int size){
        n=size;
        arr=vector<int>(size+1);
        arr[0]=0;
        for(int i=0;i<n;i++){
            addValue(i,1);
        }
    }
    void addValue(int i,int val){
        i++;
        while(i<arr.size()){
            arr[i]+=val;
            i=getNext(i);                
        }
    }
    int getSum(int i){
        i++;
        int sum=0;
        while(i>0){
            sum+=arr[i];
            i=getParent(i);
        }
        return sum;
    }
};
class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        vector<long long> sum(nums.size()+1,0);
        for(int i=0;i<nums.size();i++){
            sum[i+1]=sum[i]+nums[i];
        }
        vector<long long> temp(sum.begin(),sum.end());
        sort(temp.begin(),temp.end());
        BIT tree(temp.size());
        int count=0;
        for(long long &x:sum){
            int ind=lower_bound(temp.begin(),temp.end(),x)-temp.begin();
            int lowerind=lower_bound(temp.begin(),temp.end(),x+lower)-temp.begin();
            int upperind=upper_bound(temp.begin(),temp.end(),x+upper)-temp.begin()-1;
            tree.addValue(ind,-1);
            count+=tree.getSum(upperind)-tree.getSum(lowerind-1);
        }
        return count;
    }
};