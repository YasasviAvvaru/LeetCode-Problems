class Solution {
public:
    int climbStairs(int n) {
        int st=1,mid=1,end=0;
        if(n<2)return 1;
        for(int i=2;i<=n;i++){
            end=st+mid;
            st=mid;
            mid=end;
        }
        return end;
    }
};