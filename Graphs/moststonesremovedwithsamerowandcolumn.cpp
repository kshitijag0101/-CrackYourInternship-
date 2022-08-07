class Solution {
public:
    int parent[20005]={-1};
    int rank[20005]={1};
    int find(int x){
        if(x==parent[x]) return x;
        return (parent[x]=find(parent[x]));
    }
    void unionn(int x,int y){
        int x_rep=find(x),y_rep=find(y);
        if(x_rep==y_rep) return;
        if(rank[x_rep]<rank[y_rep]){
            parent[x_rep]=y_rep;
        }
        else if(rank[y_rep]<rank[x_rep]){
            parent[y_rep]=x_rep;
        }
        else{
            parent[y_rep]=x_rep;
            rank[x_rep]++;
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        for(int i=0;i<20005;i++){
            parent[i]=i;
        } 
        for(vector<int> stone:stones){
            unionn(stone[0],stone[1]+10001);
        }
        set<int> s;
        for(vector<int> stone:stones){
            s.insert(find(stone[0]));
        }
        int connected=s.size();
        return stones.size()-connected;
    }
};