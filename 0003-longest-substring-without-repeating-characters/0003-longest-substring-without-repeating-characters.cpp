class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans=0;
        int i=0,n=s.size();
        map<char,int>mp;
        for(int j=0;j<n;j++){
            //step-1 : unconditional addition.
            mp[s[j]]++;

            //step-2 : shrink from left to get valid range.
            if(mp[s[j]]>1){
                while(i<=j and mp[s[i]]==1){
                    mp[s[i]]--;
                    i++;
                }
                mp[s[j]]--;
                i++;
            }

            //step-3 : as [i,j] is valid range,calculate ans
            ans=max(ans,j-i+1);
        }
        return ans;
    }
};