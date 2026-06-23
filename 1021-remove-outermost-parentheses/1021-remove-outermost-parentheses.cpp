class Solution {
public:
    string removeOuterParentheses(string s) {
        // stack<char>st;
        // set<int>v;
        // st.push(s[0]);
        // int l=0,i=1,n=s.size();
        // while(i<n){
        //     if(st.top()==s[i]){
        //         st.push(s[i]);
        //     }
        //     else{
        //         st.pop();
        //     }
        //     if(st.empty()){
        //         v.insert(l);
        //         v.insert(i);
        //         l=i+1;
        //         if(l<n)st.push(s[l]);
        //     }
        //     i++;
        // }
        // string x;
        // for(int i=0;i<n;i++){
        //     if(v.find(i)!=v.end()){
        //         x.push_back(s[i]);
        //     }
        // }
        // return x;
        stack<char>st;
        set<int>v;
        int n=s.size(),l=0;
        for(int i=0;i<n;i++){
            if(st.empty() and s[i]=='('){
                st.push('(');
                l=i;
            }
            else if(st.top()==s[i]){
                st.push(s[i]);
            }
            else{
                st.pop();
            }
            if(st.empty()){
                v.insert(i);
                v.insert(l);
            }
        }
        string x;
        for(int i=0;i<n;i++){
            if(v.find(i)==v.end()){
                x.push_back(s[i]);
            }
        }
        return x;
    }
};