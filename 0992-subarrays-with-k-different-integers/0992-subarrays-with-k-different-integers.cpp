class Solution {
public:
    int subarraysWithKDistinct(vector<int>& s , int k) {
        int i1=0,i2=0,ct1=0,ct2=0;
        int ans=0;
        map<int,int>mp1;
        map<int,int>mp2;
        for(int j=0;j<s.size();j++){
            mp1[s[j]]++;
            if(mp1[s[j]]==1)ct1++;
            
            mp2[s[j]]++;
            if(mp2[s[j]]==1)ct2++;

            while(ct1>k and i1<=j){
                mp1[s[i1]]--;
                if(mp1[s[i1]]==0)ct1--;
                i1++;
            }

            while(ct2>k-1 and i2<=j){
                mp2[s[i2]]--;
                if(mp2[s[i2]]==0)ct2--;
                i2++;
            }

            ans+=(i2-i1);
        }
        return ans;
    }
};
