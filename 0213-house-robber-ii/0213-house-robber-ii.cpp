class Solution {
public:
    int fxn(vector<int>& nums,int st,int end){
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(2,0));
        if(st>end or end<0)return 0;
        dp[end][0]=nums[end];
        dp[end][1]=0;
        for(int i=end-1;i>=st;i--){
            dp[i][0]=dp[i+1][1]+nums[i];
            dp[i][1]=max(dp[i+1][0],dp[i+1][1]);
        }
        return max(dp[st][0],dp[st][1]);
    }
    int rob(vector<int>& nums) {
        //case1->none of 0,n-1 chosen.
        int n=nums.size();
        int c1=fxn(nums,1,n-2);

        //case2->0 chosen ,n-1 not chosen
        int c2=nums[0]+fxn(nums,2,n-2);

        int c3=nums[n-1]+fxn(nums,1,n-3);

        return max(max(c1,c2),c3);
    }
};