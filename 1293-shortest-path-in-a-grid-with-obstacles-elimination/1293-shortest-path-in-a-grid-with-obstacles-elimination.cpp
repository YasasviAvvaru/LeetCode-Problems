class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();

        vector<vector<vector<int>>> dist(
            n, vector<vector<int>>(m, vector<int>(k + 1, -1))
        );

        vector<int> dx = {1, -1, 0, 0};
        vector<int> dy = {0, 0, 1, -1};

        queue<array<int, 3>> q; // {x, y, obstacles_used}
        q.push({0, 0, 0});
        dist[0][0][0] = 0;

        while (!q.empty()) {
            auto [x, y, used] = q.front();
            q.pop();

            for (int dir = 0; dir < 4; dir++) {
                int nx = x + dx[dir];
                int ny = y + dy[dir];

                if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                    continue;

                int nused = used + grid[nx][ny];

                if (nused > k)
                    continue;

                if (dist[nx][ny][nused] != -1)
                    continue;

                dist[nx][ny][nused] = dist[x][y][used] + 1;
                q.push({nx, ny, nused});
            }
        }

        int ans = INT_MAX;
        for (int d : dist[n - 1][m - 1]) {
            if (d != -1)
                ans = min(ans, d);
        }

        return ans == INT_MAX ? -1 : ans;
    }
};