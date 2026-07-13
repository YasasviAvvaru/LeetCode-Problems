class Solution {
public:
    int  mask(vector<int>& f){
        int ans=0;
        for(int i=0;i<26;i++){
            if(f[i]%2!=0){
                ans+=(1<<i);
            }
        }
        return ans;
    }
    void dfs(int u,vector<int>& f,vector<vector<pair<int,char>>>& adj,vector<int>& dp){
        dp[u]=mask(f);
        for(auto& [v,c]:adj[u]){
            f[c-'a']++;
            dfs(v,f,adj,dp);
            f[c-'a']--;
        }
        return;
    }
    long long countPalindromePaths(vector<int>& parent, string s) {
        int n=parent.size();
        vector<vector<pair<int,char>>>adj(n);
        for(int i=1;i<n;i++){
            adj[parent[i]].push_back({i,s[i]});
        }
        vector<int>f(26),dp(n);
        dfs(0,f,adj,dp);

        unordered_map<int,int>mp;
        long long ans=0;
        mp[0]=1;
        for(int i=1;i<n;i++){
            ans+=mp[dp[i]];
            for(int j=0;j<26;j++){
                ans+=(mp[dp[i]^(1<<j)]);
            }
            mp[dp[i]]++;
        }
        return ans;
    }
};