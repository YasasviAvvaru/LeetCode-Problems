class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& g) {
        vector<vector<int>>dp(g);
        int m=g.size(),n=g[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(g[i][j]==1)dp[i][j]=0;
                else if(i==0 and j==0)dp[i][j]=1;
                else if(i>0 and j==0){
                    dp[i][j]=dp[i-1][j];
                }
                else if(j>0 and i==0)dp[i][j]=dp[i][j-1];
                else dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};