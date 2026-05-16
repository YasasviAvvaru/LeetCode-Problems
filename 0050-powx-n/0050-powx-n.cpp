class Solution {
public:
    double fxn(double x,long long n){
        if(n<0){
            x=1/x;
            n*=-1;
        }
        if(n==0)return 1;
        if(n==1)return x;
            auto ans=myPow(x,n/2);
        if(n%2==0){
            return ans*ans;
        }
        return x*ans*ans;
    }
    
    double myPow(double x, int n) {
        long long n1=n;
        return fxn(x,n1);
    }
};