class Solution {
public:
    int numberOfSubstrings(string s) {
        int i=0,ans=0,n=s.size();
        map<int,int>mp;
        for(int j=0;j<n;j++){
            mp[s[j]]++;

            while(mp['a']>0 and mp['b']>0 and mp['c']>0 and i<=j){
                ans+=n-j;
                mp[s[i]]--;
                i++;
            }

        }
        return ans;
    }
};