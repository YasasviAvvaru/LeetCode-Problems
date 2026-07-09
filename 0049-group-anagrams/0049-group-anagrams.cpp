class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
       map<string,vector<string>>mp;
       for(auto& x:strs){
            string y=x;
            sort(y.begin(),y.end());
            mp[y].push_back(x);
       }
       vector<vector<string>>ans;
       for(auto& [s,v]:mp){
        ans.push_back(v);
       }
       return ans;
    }
};