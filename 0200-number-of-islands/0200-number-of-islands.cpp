class Solution {
    void bfs(vector<vector<char>>& grid, int sx, int sy) {
        int r = grid.size(), c = grid[0].size();
        queue<pair<int,int>> q;
        q.push({sx, sy});
        grid[sx][sy] = '0'; // sink immediately on enqueue
        
        constexpr int dx[]{1,-1,0,0};
        constexpr int dy[]{0,0,1,-1};
        
        while (!q.empty()) {
            auto [x, y] = q.front(); q.pop();
            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k], ny = y + dy[k];
                if (nx>=0 && ny>=0 && nx<r && ny<c && grid[nx][ny]=='1') {
                    grid[nx][ny] = '0'; // sink on enqueue, not dequeue
                    q.push({nx, ny});
                }
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        for (int i = 0; i < (int)grid.size(); i++)
            for (int j = 0; j < (int)grid[0].size(); j++)
                if (grid[i][j] == '1') { bfs(grid, i, j); ans++; }
        return ans;
    }
};