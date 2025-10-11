class Solution {
public:
    int mySqrt(int x) {
        long long st=0,end=x,mid=0,val;
        while(st<=end){
            mid=st+((end-st)/2);
            val=mid*mid;
            if(val==x)return mid;
            if(val<x)st=mid+1;
            if(val>x)end=mid-1;
        }
        return end;
    }
};