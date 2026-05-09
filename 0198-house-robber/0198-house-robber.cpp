class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(2,0));
        dp[n-1]={nums[n-1],0};
        for(int i=n-2;i>=0;i--){
            dp[i][0]=dp[i+1][1]+nums[i];
            dp[i][1]=max(dp[i+1][0],dp[i+1][1]);
        }
        return max(dp[0][0],dp[0][1]);
    }
};