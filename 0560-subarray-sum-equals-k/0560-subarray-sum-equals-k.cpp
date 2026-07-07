class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<long long,int>mp;
        long long sum=0;
        int n=nums.size();
        int ans=0;
        mp[0]=1;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            ans+=mp[sum-k];
            mp[sum]++;
        }
        return ans;
    }
};