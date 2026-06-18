class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& adj) {
      int n=adj.size();
      vector<vector<int>>radj(n);
      vector<int>indeg(n),ans;
      queue<int>q;
      for(int i=0;i<n;i++){
        indeg[i]=adj[i].size();
        for(auto& v:adj[i]){
            radj[v].push_back(i);
        }
      }
      for(int i=0;i<n;i++)if(indeg[i]==0)q.push(i); 
      while(!q.empty()){
        int u=q.front();q.pop();
        ans.push_back(u);
        for(auto& v:radj[u]){
            indeg[v]--;
            if(indeg[v]==0)q.push(v);
        }
      }
      sort(ans.begin(),ans.end());
      return ans; 
    }
};