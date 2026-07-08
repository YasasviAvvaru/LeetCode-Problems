class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans="";
        int n=INT_MAX;
        for(auto& str:strs){
            int z=str.size();
            n=min(n,z);
        }
        for(int i=0;i<n;i++){
            char c=strs[0][i];
            for(int j=1;j<strs.size();j++){
                if(c!=strs[j][i]){
                    return ans;
                }
            }
            ans.push_back(c);
        }
        return ans;
    }
};