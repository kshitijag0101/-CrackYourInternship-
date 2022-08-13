class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int res=0,val=intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            if(val<=intervals[i][0]){
                val=intervals[i][1];
            }
            else if(val<=intervals[i][1]){
                res++;
            }
            else if(val>intervals[i][1]){
                res++;
                val=intervals[i][1];
            }
        }
        return res;
    }
};