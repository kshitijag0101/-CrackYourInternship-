#include<bits/stdc++.h>
using namespace std;
void badchartable(string str,int size,int badchar[256]){
    for(int i=0;i<256;i++){
        badchar[i]=-1;
    }
    for(int i=0;i<size;i++){
        badchar[(int) str[i]]=i;
    }
}
void search(string text,string pat){
    int m=pat.length();
    int n=text.length();
    int badchar[256];
    badchartable(pat,m,badchar);
    int i=0;
    while(i<=(n-m)){
        int j=m-1;
        while(j>=0 && pat[j]==text[i+j]){
            j--;
        }
        if(j<0){
            cout<<"Pattern found at index :- "<<i<<endl;
            i+=(i+m<n)?m-badchar[text[i+m]]:1;
        }
        else{
            i+=max(1,j-badchar[text[i+j]]);
        }
    }
}
int main(){
    string text,pat;
    getline(cin,text);
    getline(cin,pat);
    search(text,pat);
}