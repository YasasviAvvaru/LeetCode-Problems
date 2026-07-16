class Solution {
public:
    const int MOD = 1e9 + 7;

    vector<int> dijkstra(vector<vector<pair<int,int>>> &adj) {
        int n = adj.size();
        vector<int> dist(n, INT_MAX);

        priority_queue<pair<int,int>,
                       vector<pair<int,int>>,
                       greater<pair<int,int>>> pq;

        dist[n - 1] = 0;
        pq.push({0, n - 1});

        while (!pq.empty()) {
            auto [du, u] = pq.top();
            pq.pop();

            if (du != dist[u]) continue;

            for (auto &[w, v] : adj[u]) {
                if (dist[v] > du + w) {
                    dist[v] = du + w;
                    pq.push({dist[v], v});
                }
            }
        }

        return dist;
    }

    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(n);

        for (auto &e : edges) {
            int u = e[0] - 1;
            int v = e[1] - 1;
            int w = e[2];

            adj[u].push_back({w, v});
            adj[v].push_back({w, u});
        }

        vector<int> dist = dijkstra(adj);

        vector<int> ord(n);
        iota(ord.begin(), ord.end(), 0);

        sort(ord.begin(), ord.end(),
             [&](int a, int b) {
                 return dist[a] < dist[b];
             });

        vector<int> dp(n, 0);
        dp[n - 1] = 1;

        for (int u : ord) {
            for (auto &[w, v] : adj[u]) {
                if (dist[v] > dist[u]) {
                    dp[v] += dp[u];
                    if (dp[v] >= MOD) dp[v] -= MOD;
                }
            }
        }

        return dp[0];
    }
};