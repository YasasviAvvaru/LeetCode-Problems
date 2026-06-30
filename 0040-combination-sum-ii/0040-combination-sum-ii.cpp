class Solution {
public:
    void dfs(vector<vector<int>>& ans,map<int,int>& mp,vector<int>& vals,map<int, int>::iterator ptr,int sum,int t){
        if(ptr==mp.end()){
            if(sum==t)ans.push_back(vals);
            return ;
        }
        
        if(sum<=t){
            auto nxt=ptr;
            dfs(ans,mp,vals,++nxt,sum,t);
        }
        if(ptr->first+sum<=t){
            if(ptr->second>0){
                vals.push_back(ptr->first);
                ptr->second--;
                dfs(ans,mp,vals,ptr,sum+ptr->first,t);
                vals.pop_back();
                ptr->second++;
            }
        }

        return ;

    }
    vector<vector<int>> combinationSum2(vector<int>& v, int t) {
        vector<vector<int>>ans;
        vector<int> vals;
        map<int,int>mp;
        for(auto& x:v){
            mp[x]++;
        }
        auto ptr=mp.begin();
        dfs(ans,mp,vals,ptr,0,t);
        return ans;
    }
};