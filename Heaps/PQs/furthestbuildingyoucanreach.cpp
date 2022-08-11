class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int> pq;
        for(int i=0;i<heights.size()-1;i++){
            if(heights[i+1]>heights[i]){
                if(ladders){
                    pq.push(heights[i]-heights[i+1]);
                    ladders--;
                }
                else if(!pq.empty() && (heights[i+1]-heights[i])>=pq.top()){
                    pq.push(heights[i]-heights[i+1]);
                    bricks+=pq.top();
                    pq.pop();
                }
                else{
                    bricks-=(heights[i+1]-heights[i]);
                }
                if(bricks<0) return i;
            }
        }
        return heights.size()-1;
    }
};