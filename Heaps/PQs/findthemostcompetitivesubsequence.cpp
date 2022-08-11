// Using Priority Queue

class Solution {
public:
    struct mycmp{
        bool operator()(pair<int,int> n1,pair<int,int> n2){
            if(n1.second>n2.second)   return true;
            else if(n1.second<n2.second)  return false;
            else    return n1.first>n2.first;
        }
    };
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        vector<int> res;
        priority_queue<pair<int,int>,vector<pair<int,int>>,mycmp> pq;
        for( int i=0;i<nums.size()-k;i++){
            pq.push({i,nums[i]});
        }
        for(int i=k,pre_idx=-1;0<i;i--){
            int ind=nums.size()-i;
            if(ind<nums.size())
                pq.push({ind,nums[ind]});
            while(pq.top().first<pre_idx)
                pq.pop();
            res.push_back(pq.top().second);
            pre_idx=pq.top().first;
            pq.pop();
        }
        return res;
    }
};

// Using Stack

class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        int del=nums.size()-k;
        vector<int>st;
        for(int x:nums){
            while(!st.empty() && x<st.back() && del){
                st.pop_back();
                del--;
            }
            st.push_back(x);
        }
        return vector<int>(st.begin(),st.begin()+k);
    }
};