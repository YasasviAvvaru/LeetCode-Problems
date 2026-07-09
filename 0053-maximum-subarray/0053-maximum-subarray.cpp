class Solution {
public:
    int maxSubArray(vector<int>& v) {
        int sum=0,ans=INT_MIN,n=v.size();
        for(int i=0;i<n;i++){
            sum=max(sum+v[i],v[i]);
            ans=max(ans,sum);
        }
        return ans;
    }
};