class Solution {
public:
    int mySqrt(int x) {
        long long st=0,end=x,mid=0;
        while(st<=end){
            mid=st+((end-st)/2);
            if(mid*mid==x)return mid;
            if((mid+1)*(mid+1)<x)st=mid+1;
            if((mid+1)*(mid+1)==x)return mid+1;
            if((mid+1)*(mid+1)>x and mid*mid<x)return mid;
            if(mid*mid>x)end=mid-1;
        }
        return mid;
    }
};