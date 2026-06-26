class Solution {
public:
    // bool checksorted(vector<int>& v,int st,int end){
    //     int l=st,r=end-1,mid,ans=end;
    //     //bool fxn -> v[mid]>v[mid+1].
    //     while(l<=r){
    //         int mid=(l+r)/2;

    //         if(v[mid]>v[mid+1]){
    //             ans=mid;
    //             return true;
    //         }
    //         else{}
    //     }
    // }
    int findPeakElement(vector<int>& nums) {
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]>nums[i+1])return i;
        }
        return nums.size()-1;
    }
};