class Solution {
public:
    void dfs(vector<string>& v,string& cur,int imb,int n){
        if(cur.size()==n){
            if(imb==0)v.push_back(cur);
            return;
        }
        //currently string has f->( and c-f->)
        //a)cur[last]=)->bal if 2*f=c
        //b)cur[last]=(->bal

        cur.push_back('(');
        dfs(v,cur,imb+1,n);
        cur.pop_back();

        if(imb>0){
            cur.push_back(')');
            dfs(v,cur,imb-1,n);
            cur.pop_back();
        }

        return ;
    }
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
                //imb=0 and want )
                if(st.empty())return {false,""};

                //imb--
                else{
                    st.pop();
                }
            }
        }
        //if imb>0
        if(!st.empty())return {false,""};
        return {true,s};
    }
    vector<string> generateParenthesis(int n) {
        vector<string>v;
        string s="";
        dfs(v,s,0,2*n);
        return v;
    }
};