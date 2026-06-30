class Solution {
public:
    void dfs(vector<vector<int>>& ans,vector<int>& v,int i,int sum,vector<int>& vals,int t){
        if(i==v.size()){
            if(sum==t)ans.push_back(vals);
            return;
        }

        if(v[i]+sum<=t){
            vals.push_back(v[i]);
            dfs(ans,v,i,sum+v[i],vals,t);
            vals.pop_back();
        }
        if(sum<=t){
            dfs(ans,v,i+1,sum,vals,t);
        }
    
        return ;
    }
    vector<vector<int>> combinationSum(vector<int>& v, int t) {
        vector<vector<int>>ans;
        vector<int>vals;
        dfs(ans,v,0,0,vals,t);
        return ans;
    }
};