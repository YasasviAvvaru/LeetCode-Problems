class Solution {
public:
    bool isvalid(int x,int t){
        return (x<=t);
    }
    int search(vector<int>& nums, int target) {
        int l=0,n=nums.size(),r=n-1,mid,ans=-1;
        while(l<=r){
            mid=(l+r)/2;

            if(isvalid(nums[mid],target)){
                ans=mid;
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        if(ans!=-1 and nums[ans]!=target)ans=-1;
        return ans;
    }
};