class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        for(char ch:num){
            while(!st.empty() && k>0 && st.top()>ch){
                st.pop();
                k--;
            }
            if(!st.empty() || ch!='0'){
                st.push(ch);
            }
        }
        while(!st.empty() && k--){
            st.pop();
        }
        if(st.empty()) return "0";
        int n=num.size();
        while(!st.empty()){
            num[n-1]=st.top();
            st.pop();
            n--;
        }
        return num.substr(n);
    }
};