class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& v1, vector<int>& v2) {
        int n1=v1.size(),n2=v2.size();
        
        map<int,int>mp;
        for(int i=0;i<n2;i++){
            mp[v2[i]]=i;
        }

        vector<int>sf(n2);
        stack<int>st;
        st.push(n2-1);
        sf[n2-1]=-1;

        for(int i=n2-2;i>=0;i--){
            while(!st.empty() and v2[st.top()]<v2[i]){
                st.pop();
            }
            if(st.empty())sf[i]=-1;
            else sf[i]=st.top();
            
            st.push(i);
        }

        vector<int>ans;
        for(auto& x:v1){
            if(sf[mp[x]]==-1)ans.push_back(sf[mp[x]]);
            else ans.push_back(v2[sf[mp[x]]]);
        }
        return ans;
    }
};