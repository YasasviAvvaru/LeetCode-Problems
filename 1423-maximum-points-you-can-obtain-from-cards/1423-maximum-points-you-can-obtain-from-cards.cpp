class Solution {
public:
    int maxScore(vector<int>& v, int k) {
        int n=v.size();
        vector<int>pf(n+1);
        for(int i=0;i<n;i++){
            pf[i+1]=pf[i]+v[i];
        }

        //i= number of elements from left chosen.
        //ans=pf[i]+pf[n]-pf[n+i-k]
        //left over= k-i elements.
        //n-x=k-i->x=n+i-k.
        int ans=INT_MIN;
        for(int i=0;i<=k;i++){
            ans=max(ans,pf[i]+pf[n]-pf[n+i-k]);
        }
        return ans;
    }
};