class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int time=0;
        if(colors.length()<=1) return time;
        for(int i=1;i<colors.length();i++){
            if(colors[i]==colors[i-1]){
                time+=min(neededTime[i],neededTime[i-1]);
                neededTime[i]=max(neededTime[i],neededTime[i-1]);
            }
        }
        return time;
    }
};