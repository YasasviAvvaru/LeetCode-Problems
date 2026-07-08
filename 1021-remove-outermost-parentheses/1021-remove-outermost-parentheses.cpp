class Solution {
public:
    string removeOuterParentheses(string s) {
        //if a ( has no unbalanced ( in prefix then it is an outer most paranthesis.

        stack<pair<int,int>>st;
        vector<int>v;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(' and st.empty()){
                st.push({1,i});
            }
            else if(s[i]=='('){
                st.push({0,i});
            }
            else if(s[i]==')' and st.top().first==1){
                v.push_back(i);
                v.push_back(st.top().second);
                st.pop();
            } 
            else st.pop();
        }
        sort(v.begin(),v.end());
        string ans;
        for(int i=s.size()-1;i>=0;i--){
            if(v.back()!=i){
                ans.push_back(s[i]);
            }
            else v.pop_back();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};