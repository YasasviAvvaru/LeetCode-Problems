class Solution {
public:
    void dfs(int u,vector<vector<int>>& adj,vector<int>& vis){
        vis[u]=1;
        for(auto& v:adj[u]){
            if(!vis[v])dfs(v,adj,vis);
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        int m=connections.size();
        if(m<(n-1))return -1;
        int ans=-1;
        vector<int>vis(n);
        vector<vector<int>>adj(n);
        for(auto& x:connections){
            int u=x[0],v=x[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,adj,vis);
                ans++;
            }
        }
        return ans;
    }
};