class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<int> pq,temp;
        int n=nums.size();
        for(int i=0;i<k;i++){
            pq.push(nums[i]);
        }
        vector<int> res;
        res.push_back(pq.top());
        for(int i=k;i<n;i++){
            if(pq.top()==nums[i-k]){
                pq.pop();
            }
            else{
                temp.push(nums[i-k]);
            }
            while(!temp.empty() && temp.top()==pq.top()){
                temp.pop();
                pq.pop();
            }
            pq.push(nums[i]);
            res.push_back(pq.top());
        }
        return res;
    }
};