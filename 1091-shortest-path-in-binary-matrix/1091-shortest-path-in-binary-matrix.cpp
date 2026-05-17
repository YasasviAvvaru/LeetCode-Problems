class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int dr[8] = {-1,-1,-1,0,0,1,1,1};
        int dc[8] = {-1,0,1,-1,1,-1,0,1};
        vector<vector<int>>dist(n,vector<int>(n,-1));

        if(grid[0][0]==1)return -1;

        queue<pair<int,int>>q;
        q.push({0,0});
        dist[0][0]=1;
        while(!q.empty()){
            auto [ux,uy]= q.front();q.pop();

            for(int k=0;k<8;k++){
                auto nx=ux+dr[k],ny=uy+dc[k];
                if(nx>=0 and ny>=0 and nx<n and ny<n){
                    if(grid[nx][ny]==0 and dist[nx][ny]==-1){
                        dist[nx][ny]=dist[ux][uy]+1;
                        q.push({nx,ny});
                    }
                }
            }
        }
        return dist[n-1][n-1];
    }
};