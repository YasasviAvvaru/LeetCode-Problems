class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
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
        if(ans.size()!=n)return {};
        return ans;
    }
};