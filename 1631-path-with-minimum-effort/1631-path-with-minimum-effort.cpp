class Solution {
public:
    vector<vector<int>> dirs = {{-1,0},{1,0},{0,-1},{0,1}};

    int dijkstraGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dist(n, vector<int>(m, 1e9));

        // {distance, row, col}
        priority_queue<
            vector<int>,
            vector<vector<int>>,
            greater<vector<int>>
        > pq;

        dist[0][0] = 0;
        pq.push({dist[0][0], 0, 0});

        while (!pq.empty()) {
            auto cur = pq.top();
            pq.pop();

            int d = cur[0];
            int r = cur[1];
            int c = cur[2];

            // skip outdated states
            if (d > dist[r][c]) continue;

            for (auto &dir : dirs) {
                int nr = r + dir[0];
                int nc = c + dir[1];

                if (nr >= 0 && nr < n && nc >= 0 && nc < m) {

                    int newDist = max(dist[r][c],abs(grid[nr][nc]-grid[r][c]));

                    if (newDist < dist[nr][nc]) {
                        dist[nr][nc] = newDist;
                        pq.push({newDist, nr, nc});
                    }
                }
            }
        }

        return dist[n-1][m-1];
    }
    int minimumEffortPath(vector<vector<int>>& grid) {
        return dijkstraGrid(grid);
    }
};