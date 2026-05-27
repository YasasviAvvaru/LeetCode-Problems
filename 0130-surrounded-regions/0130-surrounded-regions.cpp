class Solution {
public:
    void grid_bfs(vector<vector<char>>& grid,vector<vector<bool>>& d){
        int r = grid.size(), c = grid[0].size();
        int dx[4] = {1,-1,0,0};
        int dy[4] = {0,0,1,-1};
        queue<pair<int,int>> q;

        for(int j=0;j<c;j++){
            if(grid[0][j]=='O'){
                q.push({0,j});
                d[0][j]=true;
            }
            if(grid[r-1][j]=='O'){
                q.push({r-1,j});
                d[r-1][j]=true;
            }
        }
        for(int i=1;i<r-1;i++){
            if(grid[i][0]=='O'){
                q.push({i,0});
                d[i][0]=true;
            }
            if(grid[i][c-1]=='O'){
                q.push({i,c-1});
                d[i][c-1]=true;
            }
        }

        while(!q.empty()){
            auto [x,y] = q.front(); q.pop();
            for(int k = 0; k < 4; k++){
                int nx = x + dx[k], ny = y + dy[k];
                if(nx>=0 && ny>=0 && nx<r && ny<c && d[nx][ny]==false and grid[nx][ny]=='O'){
                    d[nx][ny] = true;
                    q.push({nx,ny});
                }
            }
        }
    }
    void solve(vector<vector<char>>& g) {
        int r=g.size(),c=g[0].size();
        vector<vector<bool>> d(r,vector<bool>(c,false));
        grid_bfs(g,d);
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(!d[i][j])g[i][j]='X';
            }
        }
    }
};