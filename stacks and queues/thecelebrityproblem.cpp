#include<bits/stdc++.h>
using namespace std;
bool MATRIX[4][4] = {{0, 0, 1, 0},
                    {0, 0, 1, 0},
                    {0, 0, 0, 0},
                    {0, 0, 1, 0}};
bool knows(int a, int b){
    return MATRIX[a][b];
}
int findCelebrity(int n){
    stack<int> st;
    int C;
    for(int i=0;i<n;i++){
        st.push(i);
    }
    while(st.size()>1){
        int A=st.top();st.pop();
        int B=st.top();st.pop();
        if(knows(A,B)) st.push(B);
        else st.push(A);
    }
    C=st.top();st.pop();
    for(int i=0;i<n;i++){
        if(i!=C && (knows(C,i) || !knows(i,C))) return -1;
    }
    return C;
}
int main(){
    int n = 4;
    int id = findCelebrity(n);
    id==-1?cout << "No celebrity":cout << "Celebrity ID " << id;
    return 0;
}