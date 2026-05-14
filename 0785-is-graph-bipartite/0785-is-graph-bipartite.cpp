class Solution {
public:
    bool bfs(int src,vector<vector<int>>& graph,
    vector<int>& vis,vector<int>& par){
        int n=graph.size();
        queue<int>q;
        par[src]=0;
        q.push(src);
        vis[src]=1;
        while(!q.empty()){
            int u=q.front();q.pop();
            for(auto& v:graph[u]){
                if(!vis[v]){
                    q.push(v);
                    vis[v]=1;
                    par[v]=(par[u]+1)%2;
                }
                else if(par[v]==par[u])return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        bool ok=true;
        vector<int>vis(n);
        vector<int>par(n,-1);
        for(int i=0;i<n;i++){
            if(!vis[i])ok=ok and bfs(i,graph,vis,par);
        }
        return ok;
    }
};