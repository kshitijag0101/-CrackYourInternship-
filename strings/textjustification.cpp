#include<bits/stdc++.h>
using namespace std;
vector<string> fullJustify(vector<string>& words, int maxWidth) {
    vector<string> res;
    for(int i=0,j=0;i<words.size();j=++i){
        int width=0;
        while(i<words.size() && width+words[i].length()+(i-j)<=maxWidth){
            width+=words[i].length();
            i++;
        }
        i--;
        string line;
        int sp=maxWidth-width;
        int gap=(i==j || i==words.size()-1?1:sp/(i-j));
        int extra=(i==j || i==words.size()-1?0:sp%(i-j));
        while(j<=i){
            if(!line.empty()){
                line+=string(gap,' '),sp-=gap;
                if(extra) line+=' ',extra--,sp--;
            }
            line+=words[j++];
        }
        line+=string(sp,' ');
        res.push_back(move(line));
    }
    return res;
}
int main(){
    int n,maxWidth;
    cin>>n;
    string word;
    vector<string> words;
    for(int i=0;i<n;i++){
        cin>>word;
        words.push_back(word);
    }
    cin>>maxWidth;
    vector<string> res=fullJustify(words,maxWidth);
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<endl;
    }
}