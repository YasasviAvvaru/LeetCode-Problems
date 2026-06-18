class Solution {
public:
    // vector<int> state;
    // bool dfs(int u,vector<vector<int>>& adj){
    //     state[u]=1;
    //     for(auto& v:adj[u]){
    //         if(state[v]==0){
    //             if(dfs(v,adj))return true;
    //         }
    //         else if(state[v]==1)return true;
    //     }
    //     state[u]=2;
    //     return false;
    // }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        vector<int>ans;
        queue<int>q;
        vector<int>indeg(n);
        vector<vector<int>>adj(n);
        for(auto& node:prerequisites){
            indeg[node[0]]++;
            adj[node[1]].push_back(node[0]);
        }
        for(int i=0;i<n;i++)if(indeg[i]==0)q.push(i);

        while(!q.empty()){
            auto u=q.front();q.pop();
            ans.push_back(u);
            for(auto& v:adj[u]){
                indeg[v]--;
                if(indeg[v]==0)q.push(v);
            }
        }
        if(ans.size()!=n)return false;
        return true;
        // vector<vector<int>>adj(n);
        // for(auto& vec:prerequisites){
        //     adj[vec[1]].push_back(vec[0]);
        // }
        
        // state.resize(n);

        // //check for all CC.
        // for(int i=0;i<n;i++){
        //     if(state[i]==0){
        //         if(dfs(i,adj))return false;
        //     }
        // }
        // return true;

    }
};