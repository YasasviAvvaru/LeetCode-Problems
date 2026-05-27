class Solution {
public:
    
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>> d(m,vector<int>(n,-1));
        int ct0=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0)ct0++;
                if(grid[i][j]==2){
                    q.push({i,j});
                    d[i][j]=0;
                }
            }
        }
        if(ct0==m*n)return 0;
        int dx[4] = {1,-1,0,0};
        int dy[4] = {0,0,1,-1};
        while(!q.empty()){
            auto [x,y]=q.front();q.pop();
            for(int k = 0; k < 4; k++){
            int nx = x + dx[k], ny = y + dy[k];
                if(nx>=0 && ny>=0 && nx<m && ny<n && d[nx][ny]==-1 and grid[nx][ny]==1){
                    d[nx][ny] = d[x][y] + 1;
                    q.push({nx,ny});
                }
            }
        }
        int ans=INT_MIN;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]>=1){
                    if(d[i][j]>=0){
                        ans=max(ans,d[i][j]);
                    }
                    else{
                        ans=INT_MAX;
                    }
                }
            }
        }
        if(ans==INT_MAX)return -1;
        return ans;
    }
};