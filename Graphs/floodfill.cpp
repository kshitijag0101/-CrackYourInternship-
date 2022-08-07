class Solution {
public:
    void dfs(vector<vector<int>>& image, int sr, int sc, int color,int prevColor){
        if(image[sr][sc]==prevColor){
            image[sr][sc]=color;
            if(sr>=1){
                dfs(image,sr-1,sc,color,prevColor);
            }
            if(sc>=1){
                dfs(image,sr,sc-1,color,prevColor);
            }
            if(sr+1<image.size()){
                dfs(image,sr+1,sc,color,prevColor);
            }
            if(sc+1<image[0].size()){
                dfs(image,sr,sc+1,color,prevColor);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int prevColor=image[sr][sc];
        if(prevColor!=color){
            dfs(image,sr,sc,color,prevColor);
        } 
        return image;
    }
};