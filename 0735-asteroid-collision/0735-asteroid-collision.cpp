class Solution {
public:
    vector<int> asteroidCollision(vector<int>& v) {
        vector<int>ans;
        stack<int>st;
        int n=v.size();
        st.push(v[0]);
        for(int i=1;i<n;i++){
            if(v[i]>0){
                st.push(v[i]);
            }
            else{
                int val=abs(v[i]);
                while(!st.empty() and st.top()<val and st.top()>0){
                    st.pop();
                }
                if(st.empty()){
                    st.push(v[i]);
                }
                else if(st.top()<0){
                    st.push(v[i]);
                }
                else if(st.top()>val){}
                else{
                    st.pop();
                }
            }
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};