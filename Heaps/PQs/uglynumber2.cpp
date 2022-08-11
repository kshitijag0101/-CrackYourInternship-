// Priority Queue Solution

class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<long long,vector<long long>,greater<long long>> pq;
        unordered_set<long long> s;
        pq.push(1);
        s.insert(1);
        long long res=-1;
        while(n--){
            long long curr=pq.top();
            pq.pop();
            res=curr;
            long long two=curr*2;
            long long three=curr*3;
            long long five=curr*5;
            if(!s.count(two)){
                pq.push(two);
                s.insert(two);
            }
            if(!s.count(three)){
                pq.push(three);
                s.insert(three);
            }
            if(!s.count(five)){
                pq.push(five);
                s.insert(five);
            }
        }
        return (int)res;
    }
};

// DP Solution

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n);
        dp[0]=1;
        int p1=0,p2=0,p3=0;
        for(int i=1;i<n;i++){
            int two=dp[p1]*2;
            int three=dp[p2]*3;
            int five=dp[p3]*5;
            dp[i]=min(two,min(three,five));
            if(dp[i]==two) p1++;
            if(dp[i]==three) p2++;
            if(dp[i]==five) p3++;
        }
        return dp[n-1];
    }
};