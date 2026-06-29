class Solution {
public:
    pair<bool,string> isvalid(int x,int n1){
        string s;
        bool b;
        stack<char>st;
        for(int i=0;i<n1;i++){
            if(x&(1<<i)){
                s.push_back('(');
                st.push('(');
            }
            else{
                s.push_back(')');
                if(st.empty())return {false,""};
                else{
                    st.pop();
                }
            }
        }
        if(!st.empty())return {false,""};
        return {true,s};
    }
    vector<string> generateParenthesis(int n) {
        vector<string>v;
        int n1=2*n;
        for(int x=0;x<(1<<n1);x++){
            auto [b,s]=isvalid(x,n1);
            if(b)v.push_back(s);
        }
        return v;
    }
};