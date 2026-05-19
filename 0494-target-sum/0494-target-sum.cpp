class Solution {
public:
    int fxn(vector<int>& arr,int w,int i,vector<vector<int>>& dp){
        if(i==0){
            if(w==0)return 1;
            return 0;
        }

        if(dp[i][w]!=-1)return dp[i][w];

        if(arr[i-1]<=w)return dp[i][w]=(fxn(arr,w-arr[i-1],i-1,dp)+fxn(arr,w,i-1,dp));
        return dp[i][w]=fxn(arr,w,i-1,dp);
    }
    int findTargetSumWays(vector<int>& arr, int diff) {
        int sum=accumulate(arr.begin(),arr.end(),0);
        int w=(sum+diff)/2,n=arr.size();
        diff=abs(diff);
        if(diff>sum or (sum+diff)%2)return 0;
        vector<vector<int>>dp(n+1,vector<int>(w+1,-1));
        return fxn(arr,w,n,dp);
    }
};