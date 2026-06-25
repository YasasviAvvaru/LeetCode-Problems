class Solution {
public:
    bool isvalid(vector<int>& v,int idx,int val){
        return (v[idx]>=val);
    }
    int search(vector<int>& v, int target) {
        //bool fxn is f(val)= (val >= target.)
        //we find first True.
        //if(ans==target)then its idx.
        //else -1;

        //if all are <target->-1
        int l=0,r=v.size()-1,mid,ans=-1;
        while(l<=r){
            mid=(l+r)/2;
            if(isvalid(v,mid,target)){
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        if(ans==-1)return -1;
        if(v[ans]>target)return -1;
        return ans;
    }
};