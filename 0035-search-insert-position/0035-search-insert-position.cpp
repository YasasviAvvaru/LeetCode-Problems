class Solution {
public:
    bool f(int val,int x){return val>=x;}
    int searchInsert(vector<int>& v, int x) {
        //find first index >=x.
        int l=0,r=v.size()-1,mid,ans=r+1;
        while(l<=r){
            mid=(l+r)/2;

            if(f(v[mid],x)){
                ans=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }
};