class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans=-10000000,sum=-100000;
        for(auto& x:nums){
            ans=max(ans,sum);
            sum=max(sum+x,x);
        }
        ans=max(ans,sum);
        return ans;
    }
};