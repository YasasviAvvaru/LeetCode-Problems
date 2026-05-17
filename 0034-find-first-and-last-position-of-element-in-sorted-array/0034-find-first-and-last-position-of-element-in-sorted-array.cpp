class Solution {
public:
    vector<int> searchRange(vector<int>& v, int x) {
        auto it1= lower_bound(v.begin(),v.end(),x)-v.begin();
        auto it2=upper_bound(v.begin(),v.end(),x)-v.begin();

        int ct=it2-it1;
        if(ct==0)return {-1,-1};
        else return {(int)it1,(int)(it2-1)};
    }
};