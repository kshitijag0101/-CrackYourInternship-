class Solution {
public:
    bool isPalindrome(string& s,int low,int high){
        while(low<high){
            if(s[low++]!=s[high--]) return false;
        }
        return true;
    }
    void dfs(string&s,vector<vector<string>>& res,vector<string>& temp,int start){
        if(start>=s.length()) res.push_back(temp);
        for(int end=start;end<s.length();end++){
            if(isPalindrome(s,start,end)){
                temp.push_back(s.substr(start,end-start+1));
                dfs(s,res,temp,end+1);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> temp;
        dfs(s,res,temp,0);
        return res;
    }
};