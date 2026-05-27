class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& v) {
        vector<vector<int>>ans;
        sort(v.begin(), v.end(), [](const vector<int>& a, const vector<int>& b) {
    if(a[0] == b[0]) return a[1] > b[1]; // descending
    return a[0] < b[0]; // ascending
});
        int n=v.size(),l=v[0][0],r=v[0][1];
        for(int i=1;i<n;i++){
            if(v[i][0]<=min(r,v[i][1])){
                r=max(r,v[i][1]);
            }
            else{
                ans.push_back({l,r});
                l=v[i][0];r=v[i][1];
           }
        }
        ans.push_back({l,r});
        return ans;
    }
};