class Solution {
public:
    string reverseWords(string s) {
        vector<string>v;
        string s1;
        for(auto& x:s){
            if(x!=' ')s1.push_back(x);
            else if(!s1.empty()){
                v.push_back(s1);
                s1="";
            }
        }
        if(!s1.empty())v.push_back(s1);
        string S;
        for(int i=v.size()-1;i>0;i--){
            S+=v[i];
            S.push_back(' ');
        }
        S+=v[0];
        return S;
    }
};