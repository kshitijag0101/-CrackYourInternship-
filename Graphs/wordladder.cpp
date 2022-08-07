class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        map<string,vector<string>> mp;
        int msize=beginWord.size();
        for(int i=0;i<wordList.size();i++){
            string str=wordList[i];
            for(int j=0;j<msize;j++){
                string x=str.substr(0,j)+"*"+str.substr(j+1,msize-j-1);
                mp[x].push_back(str);
            }
        }
        string str=beginWord;
        for(int j=0;j<msize;j++){
            string x=str.substr(0,j)+"*"+str.substr(j+1,msize-j-1);
            mp[x].push_back(str);
        }
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        set<string> visited;
        visited.insert(beginWord);
        while(!q.empty()){
            string str=q.front().first;
            int level=q.front().second;
            q.pop();
            for(int j=0;j<msize;j++){
                string p=str.substr(0,j)+"*"+str.substr(j+1,msize-j-1);
                vector<string> v=mp[p];
                for(string x:v){
                    if(visited.find(x)==visited.end()){
                        q.push({x,level+1});
                        visited.insert(x);
                        if(x==endWord) return level+1;
                    }
                }
            }
        }
        return 0;
    }
};