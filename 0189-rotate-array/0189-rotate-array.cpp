class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>v(n);
        k=k%n;
        for(int i=0;i<n;i++){
            v[i]=nums[(n-k+i)%n];
        }
        for(int i=0;i<n;i++){
            nums[i]=v[i];
        }
    }
};