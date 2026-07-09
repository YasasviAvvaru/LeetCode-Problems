class Solution {
public:
    int maxProfit(vector<int>& v) {
        stack<int>st;
        int n=v.size();
        st.push(n-1);
        vector<int>sf(n);
        sf[n-1]=v[n-1];
        for(int i=n-2;i>=0;i--){
            sf[i]=max(sf[i+1],v[i]);
        }
        int ans=0;
        for(int i=0;i<n-1;i++){
            ans=max(ans,sf[i+1]-v[i]);
        }
        return ans;
    }
};