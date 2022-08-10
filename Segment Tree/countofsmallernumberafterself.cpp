class BIT{
public:
    int n;
    vector<int> tree;
    BIT(int n){
        this->n=n;
        tree=vector<int>(n+1);
    }
    void increase(int i){
        while(i <= n){
            ++tree[i];
            i+=i&-i;
        }
    }
    int get(int i){
        int count=0;
        while(i > 0){
            count+=tree[i];
            //go to the upper node just to its left
            i-=i&-i;
        }
        return count;
    }
};

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        if(n==0) return ans;
        int minv=*min_element(nums.begin(),nums.end());
        transform(nums.begin(), nums.end(), nums.begin(),[&minv](int num){return num - minv + 1;});
        int maxv=*max_element(nums.begin(),nums.end());
        
        BIT* bit=new BIT(maxv);
        for(int i=n-1;i>=0;i--){
            ans[i]=bit->get(nums[i]-1);
            bit->increase(nums[i]);
        }
        
        return ans;
    }
};