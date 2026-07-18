class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int n = grid.size(), m = grid[0].size();

        int stx = 0, sty = 0;
        int finalMask = 0;

        // Find start and compute final mask
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '@') {
                    stx = i;
                    sty = j;
                }
                else if ('a' <= grid[i][j] && grid[i][j] <= 'f') {
                    finalMask |= (1 << (grid[i][j] - 'a'));
                }
            }
        }

        vector<vector<vector<int>>> dist(
            n, vector<vector<int>>(m, vector<int>(64, -1)));

        queue<array<int,3>> q;
        q.push({stx, sty, 0});
        dist[stx][sty][0] = 0;

        vector<int> dx = {1, -1, 0, 0};
        vector<int> dy = {0, 0, 1, -1};

        while (!q.empty()) {
            auto [x, y, mask] = q.front();
            q.pop();

            if (mask == finalMask)
                return dist[x][y][mask];

            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];

                if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                    continue;

                if (grid[nx][ny] == '#')
                    continue;

                int newMask = mask;
                char c = grid[nx][ny];

                // Key
                if ('a' <= c && c <= 'f')
                    newMask |= (1 << (c - 'a'));

                // Lock
                if ('A' <= c && c <= 'F') {
                    if (!(mask & (1 << (c - 'A'))))
                        continue;
                }

                if (dist[nx][ny][newMask] == -1) {
                    dist[nx][ny][newMask] = dist[x][y][mask] + 1;
                    q.push({nx, ny, newMask});
                }
            }
        }

        return -1;
    }
};