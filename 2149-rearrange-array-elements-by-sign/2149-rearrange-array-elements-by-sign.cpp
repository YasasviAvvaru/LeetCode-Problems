class Solution {
public:
    vector<int> rearrangeArray(vector<int>& v) {
        int sz=v.size();
        vector<int>ans(sz,0);
        int p=0,n=1;
        for(int i=0;i<sz;i++){
            if(v[i]>0){
                ans[p]=v[i];
                p+=2;
            }
            else{
                ans[n]=v[i];
                n+=2;
            }
        }
        return ans;
    }
};