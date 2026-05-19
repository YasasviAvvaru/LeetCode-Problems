class Solution {
public:
    int coinChange(vector<int>& coins, int m) {
        vector<int>dp(m+1,-1);
        dp[0]=0;
        for(int i=1;i<=m;i++){
            int mini=INT_MAX;
            for(auto& c:coins){
                if(c<=i){
                    if(dp[i-c]!=-1)mini=min(mini,dp[i-c]);
                }
            }
            if(mini!=INT_MAX)dp[i]=1+mini;
        }
        return dp[m];
    }
};