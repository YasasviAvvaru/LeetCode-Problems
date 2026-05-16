class Solution {
public:
    int countPrimes(int n) {
        vector<bool>vis(n,false);
        int ans=0;
        for(long long i=2;i<n;i++){
            if(!vis[i]){
                ans++;
                for(long long j=i*i;j<n;j+=i){
                    vis[j]=1;
                }
            }
            
        }
        return ans;
    }
};