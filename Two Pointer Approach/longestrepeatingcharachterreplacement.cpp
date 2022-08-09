class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26);
        int l=0,res=0,maxfreq=0;
        for(int r=0;r<s.length();r++){
            freq[s[r]-'A']++;
            int currfreq=freq[s[r]-'A'];
            maxfreq=max(maxfreq,currfreq);
            while(r-l-maxfreq+1>k){
                freq[s[l]-'A']--;
                l++;
            }
            res=max(res,r-l+1);
        }
        return res;
    }
};