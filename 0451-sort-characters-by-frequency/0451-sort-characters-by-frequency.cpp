class Solution {
public:
    string frequencySort(string s) {
        map<char,int>mp;
        for(auto& x:s)mp[x]--;
        vector<pair<int,char>>v;
        string s1;
        for(auto& [x,f]:mp){
            v.push_back({-f,x});
        }
        sort(v.rbegin(),v.rend());
        for(auto& [f,x]:v){
            for(int i=0;i<f;i++)s1.push_back(x);
        }
        return s1;
    }
};