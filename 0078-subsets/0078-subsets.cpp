class Solution {
public:
    string cvt2bin(int n,int sz){
        string s;
        if(n==0){
            
        for(int i=0;i<sz;i++){
            s.push_back('0');
        }
        return s;
        }
        while(n>1){
            if(n%2==0){
                s.push_back('0');
            }
            else{
                s.push_back('1');
            }
            n/=2;
        }
        s.push_back('1');
        while(s.size()<sz){
            s.push_back('0');
        }
        reverse(s.begin(),s.end());
        return s;
    }
    void fxn(int i,vector<int>& nums,vector<vector<int>>& ans){
        vector<int>v;
        int n=nums.size();
        string s=cvt2bin(i,n);
        for(int j=n-1;j>=0;j--){
            if(s[j]=='1')v.push_back(nums[j]);
        }
        ans.push_back(v);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>ans;
        for(int i=0;i<(1<<n);i++){
            fxn(i,nums,ans);
        }
        return ans;
    }
};