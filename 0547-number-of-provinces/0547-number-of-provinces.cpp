class Solution {
public:
    void dfs(int i,vector<vector<int>>&edge,vector<int>&vis){
        vis[i]=1;
        for(auto x:edge[i]){
            if(vis[x]==0)dfs(x,edge,vis);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
       vector<vector<int>>edge(n);
       for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(isConnected[i][j]){
                edge[i].push_back(j);
            }
        }
       }
       int ct=0;
       vector<int>vis(n);
       for(int i=0;i<n;i++){
        if(vis[i]==0){
            ct++;
            dfs(i,edge,vis);
        }
       }
       return ct;
    }
    
    
};