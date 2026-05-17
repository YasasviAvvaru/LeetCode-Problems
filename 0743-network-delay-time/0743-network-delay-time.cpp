class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n);
        vector<int>dist(n,INT_MAX);

        for(auto& v:times){
            adj[v[0]-1].push_back({v[1]-1,v[2]});
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
        //{dist,vertex}
        pq.push({0,k-1});
        dist[k-1]=0;

        while(!pq.empty()){
            auto [d,u]=pq.top();pq.pop();

            if(d>dist[u])continue;

            for(auto& [v,w]:adj[u]){
                if(dist[u]+w<dist[v]){
                    dist[v]=dist[u]+w;
                    pq.push({dist[v],v});
                }
            }
        }
        int ans=INT_MIN;
        for(auto& x:dist){
            if(x==INT_MAX)return -1;
            ans=max(ans,x);
        }
        return ans;
    }
};