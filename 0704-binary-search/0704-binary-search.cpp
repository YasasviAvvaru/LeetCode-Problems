class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size(),mid=0,st=0,end=n-1;
        while(st<=end){
            mid=(st+end)/2;
            if(nums[mid]<target){
                st=mid+1;
            }
            else if(nums[mid]==target){
                return mid;
            }
            else{
                end=mid-1;
            }
        }
        if(end>=0){
            if(nums[end]==target)return end;
            else return -1;
        }
        return -1;
    }
};