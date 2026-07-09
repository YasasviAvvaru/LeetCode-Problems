class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid);
        int n=grid.size(),m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int val=INT_MAX;
                if(j>0)val=min(val,dp[i][j-1]);
                if(i>0)val=min(val,dp[i-1][j]);
                if(val!=INT_MAX){
                    dp[i][j]+=val;
                }
            }
        }
        return dp[n-1][m-1];
    }
};