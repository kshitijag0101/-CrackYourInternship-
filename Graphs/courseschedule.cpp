class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        for(vector<int> pre:prerequisites){
            graph[pre[1]].push_back(pre[0]);
        }
        vector<int> indegree(numCourses,0);
        for(int i=0;i<numCourses;i++){
            for(int x:graph[i]){
                indegree[x]++;
            }
        }
        int j;
        for(int i=0;i<numCourses;i++){
            for(j=0;j<numCourses;j++){
                if(!indegree[j]){
                    break;
                }
            }
            if(j==numCourses){
                return false;
            }
            indegree[j]=-1;
            for(int x:graph[j]){
                indegree[x]--;
            }
        }
        return true;
    }
};