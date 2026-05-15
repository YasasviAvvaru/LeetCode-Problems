class Solution {
public:
    int dijkstra(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dist(
            n,
            vector<int>(m, 1e9)
        );

        priority_queue<
            vector<int>,
            vector<vector<int>>,
            greater<vector<int>>
        > pq;

        dist[0][0] = grid[0][0];

        pq.push({dist[0][0], 0, 0});

        vector<int> dx = {-1,1,0,0};
        vector<int> dy = {0,0,-1,1};

        while(!pq.empty()){

            auto cur = pq.top();
            pq.pop();

            int d = cur[0];
            int x = cur[1];
            int y = cur[2];

            // outdated entry
            if(d > dist[x][y]) continue;

            for(int k=0;k<4;k++){

                int nx = x + dx[k];
                int ny = y + dy[k];

                // inside grid
                if(nx>=0 && ny>=0 &&
                   nx<n && ny<m){

                    int nd = max(d,grid[nx][ny]);

                    if(nd < dist[nx][ny]){

                        dist[nx][ny] = nd;

                        pq.push({nd, nx, ny});
                    }
                }
            }
        }

        return dist[n-1][m-1];
    }
    int swimInWater(vector<vector<int>>& grid) {
        return dijkstra(grid);
    }
};

//we need to find from all the paths p from (0,0) to (n-1,n-1), the path with 
//the smallest maximum wt.
//i.e min(max(weights in p))