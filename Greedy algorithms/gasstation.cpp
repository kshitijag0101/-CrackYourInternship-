class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int curr=0,total=0,start=0;
        for(int i=0;i<gas.size();i++){
            int diff=gas[i]-cost[i];
            total+=diff;
            curr+=diff;
            if(curr<0){
                start=i+1;
                curr=0;
            }
        }
        if(total>=0){
            return start;
        }
        return -1;
    }
};