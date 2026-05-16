class Solution {
public:
    int countPrimes(int n) {
        vector<int>vis(n,0);
        int ans=0;
        for(int i=2;i<n;i++){
            if(vis[i]==0)ans++;
            for(int j=2*i;j<n;j+=i){
                vis[j]=1;
            }
        }
        return ans;
    }
};