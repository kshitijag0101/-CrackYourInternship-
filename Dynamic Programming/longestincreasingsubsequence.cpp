// Time Complexity:- O(n*n) 

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        int lis[n];
        lis[0]=1;
        for(int i=0;i<n;i++){
            lis[i]=1;
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i]){
                    lis[i]=max(lis[i],lis[j]+1);
                }
            }
        }
        int res=lis[0];
        for(int i=0;i<n;i++){
            res=max(res,lis[i]);
        }
        return res;
    }
};


// Time Complexity:- O(nlogn)

class Solution {
public:
    int ceilInd(int tail[],int l,int r,int x){
        while(r>l){
            int m=l+(r-l)/2;
            if(tail[m]>=x){
                r=m;
            }
            else{
                l=m+1;
            }
        }
        return r;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        int tail[n],len=1;
        tail[0]=nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]>tail[len-1]){
                tail[len]=nums[i];
                len++;
            }
            else{
                int c=ceilInd(tail,0,len-1,nums[i]);
                tail[c]=nums[i];
            }
        }
        return len;
    }
};