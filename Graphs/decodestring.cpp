class Solution {
public:
    string decode(string& s,int& i){
        string res;
        while(i<s.length() && s[i]!=']'){
            if(isdigit(s[i])){
                int k=0;
                while(i<s.length() && isdigit(s[i])){
                    k=k*10+s[i]-'0';
                    i++;
                }
                i++;
                string r=decode(s,i);
                while(k>0){
                    res+=r;k--;
                }
                i++;
            }
            else{
                res+=s[i];
                i++;
            }
        }
        return res;
    }
    string decodeString(string s) {
        int i=0;
        return decode(s,i);
    }
};