class Solution {
public:
    int maxProfit(vector<int>& v) {
        //buy at low and sell at high.
        //for each idx i find its sf_max.
        //ans=for all i max(sf_max[i]-v[i]);
        int n=v.size();
        vector<int>sf(n,0);
        sf[n-1]=v[n-1];
        for(int i=n-2;i>=0;i--){
            sf[i]=max(sf[i+1],v[i+1]);
        }
        int ans=0;
        for(int i=0;i<n-1;i++){
            ans=max(ans,sf[i]-v[i]);
        }
        return ans;
    }
};