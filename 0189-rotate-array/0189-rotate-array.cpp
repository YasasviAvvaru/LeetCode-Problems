class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size(),k1=k%n;
        reverse(nums.begin(),nums.begin()+n-k1);
        reverse(nums.begin()+n-k1,nums.end());
        reverse(nums.begin(),nums.end());

    }
};