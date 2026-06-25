class Solution {
public:
    int isvalid(vector<int>& v,int idx){
        if(v[idx]>v[idx-1]){
            if(v[idx]>v.back())return 1;
            else return 3;
        }
        return 2;
    }
    int findMin(vector<int>& v) {
        //finding pvt.
        //1-> mid>mid-1 and mid>v[end]
        //3->mid>mid-1 and mid<=v[end]
        //2-> ans=mid and return.
        if(v.size()==1)return v[0];

        int l=1,r=v.size()-1,mid,ans=-1;
        while(l<=r){
            mid=(l+r)/2;
            int val=isvalid(v,mid);
            if(val==1){
                l=mid+1;
            }
            else if(val==2){
                ans=mid;
                return v[ans];
            }
            else r=mid-1;
        }
        return v[0];
    }
};