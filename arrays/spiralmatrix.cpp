#include<bits/stdc++.h>
using namespace std;
vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> res;
    int top=0,left=0,bottom=matrix.size()-1,right=matrix[0].size()-1;
    while(top<=bottom && left<=right){
        for(int i=left;i<=right;i++){
            res.push_back(matrix[top][i]);
        }
        top++;
        for(int i=top;i<=bottom;i++){
            res.push_back(matrix[i][right]);
        }
        right--;
        if(top<=bottom){
            for(int i=right;i>=left;i--){
                res.push_back(matrix[bottom][i]);
            }
            bottom--;
        }
        if(left<=right){
            for(int i=bottom;i>=top;i--){
                res.push_back(matrix[i][left]);
            }
            left++;
        }
    }
    return res;
}
int main(){
    int r,c,x;
    cin>>r>>c;
    vector<vector<int>> matrix;
    for(int i=0;i<r;i++){
        vector<int> mat;
        for(int j=0;j<c;j++){
            cin>>x;
            mat.push_back(x);
        }
        matrix.push_back(mat);
    }
    vector<int> res=spiralOrder(matrix);
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<" ";
    }
}