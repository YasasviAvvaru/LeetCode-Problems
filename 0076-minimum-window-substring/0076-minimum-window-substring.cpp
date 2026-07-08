class Solution {
public:
    string minWindow(string s, string t) {
        int i=0,ct=0,st=-1,ans=INT_MAX;

        map<char,int>mp,mp1;
        for(auto& x:t){mp[x]++;mp1[x]++;}
        
        for(int j=0;j<s.size();j++){
            if(mp[s[j]]>0 and mp1[s[j]]!=0)ct++;
            mp[s[j]]--;

            if(ct==t.size()){
                while(i<=j){
                    if(mp[s[i]]<0){
                        mp[s[i]]++;
                        if(j-i+1<ans){
                            st=i;
                        ans=j-i+1;
                        }
                        i++;
                    }
                    else if(mp[s[i]]==0 and mp1[s[i]]!=0){
                        if(j-i+1<ans){
                            st=i;
                        ans=j-i+1;
                        }
                        mp[s[i]]++;
                        ct--;
                        i++;
                        break;
                    }
                    else if(mp[s[i]]>=0 and mp1[s[i]]==0){
                        if(j-i+1<ans){
                            st=i;
                        ans=j-i+1;
                        }
                        mp[s[i]]++;
                        i++;
                    }
                }
            }
        }
        string x="";
        if(st!=-1)for(int i=0;i<ans;i++)x.push_back(s[i+st]);
        return x;
    }
};