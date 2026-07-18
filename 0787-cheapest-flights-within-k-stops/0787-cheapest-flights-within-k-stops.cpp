class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights,
                          int src, int dst, int k) {

        vector<vector<pair<int,int>>> adj(n);

        for (auto &f : flights)
            adj[f[0]].push_back({f[1], f[2]}); // {to,cost}

        vector<vector<int>> dist(n, vector<int>(k + 2, INT_MAX));

        priority_queue<
            vector<int>,
            vector<vector<int>>,
            greater<vector<int>>
        > pq;

        dist[src][0] = 0;
        pq.push({0, src, 0});   // {cost,node,flights_used}

        while (!pq.empty()) {
            auto cur = pq.top();
            pq.pop();

            int cost = cur[0];
            int u = cur[1];
            int used = cur[2];

            if (cost > dist[u][used]) continue;

            if (used == k + 1) continue;

            for (auto &[v, w] : adj[u]) {
                if (cost + w < dist[v][used + 1]) {
                    dist[v][used + 1] = cost + w;
                    pq.push({cost + w, v, used + 1});
                }
            }
        }

        int ans = INT_MAX;
        for (int x : dist[dst])
            ans = min(ans, x);

        return ans == INT_MAX ? -1 : ans;
    }
};