class Solution {
public:
    vector<int> rearrangeArray(vector<int>& v) {
        int sz=v.size();
        vector<int>p,n;
        for(auto& x:v){
            if(x<0)n.push_back(x);
            else p.push_back(x);
        }
        for(int i=0;i<sz/2;i++){
            v[2*i]=p[i];
            v[2*i+1]=n[i];
        }
        return v;
    }
};