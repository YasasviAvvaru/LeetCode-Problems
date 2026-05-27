class Solution {
public:
    vector<vector<int>> grid_bfs(vector<vector<int>>& grid){
        int r = grid.size(), c = grid[0].size();
        int dx[4] = {1,-1,0,0};
        int dy[4] = {0,0,1,-1};
        vector<vector<int>> d(r, vector<int>(c, -1));
        queue<pair<int,int>> q;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==0){
                    q.push({i,j});
                    d[i][j]=0;
                }
            }
        }
        while(!q.empty()){
            auto [x,y] = q.front(); q.pop();
            for(int k = 0; k < 4; k++){
                int nx = x + dx[k], ny = y + dy[k];
                if(nx>=0 && ny>=0 && nx<r && ny<c && d[nx][ny]==-1){
                    d[nx][ny] = d[x][y] + 1;
                    q.push({nx,ny});
                }
            }
        }
        return d;
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        return grid_bfs(mat);
    }
};