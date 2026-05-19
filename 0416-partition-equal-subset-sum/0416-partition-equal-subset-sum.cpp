class Solution {
public:
    bool fxn(vector<int>& arr, int w, vector<vector<int>>& dp,int i){
        //base cases
        if(w==0)return true;
        if(i==0)return false;

        //memoise check
        if(dp[i][w]!=-1)return dp[i][w]==1;

        //recursive cases
        if(arr[i-1]<=w){
            dp[i][w]= fxn(arr,w,dp,i-1)||fxn(arr,w-arr[i-1],dp,i-1);
        }
        else dp[i][w]=fxn(arr,w,dp,i-1);

        //return fxn
        return dp[i][w]==1;
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(auto& x:nums){
            sum+=x;
        }
        if(sum%2!=0)return false;
        
        int n=nums.size(),w=sum/2;
        vector<vector<int>>dp(n+1,vector<int>(w+1,-1));

        return fxn(nums,w,dp,n);
    }
};