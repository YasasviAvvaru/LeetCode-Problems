class Solution {
public:
    bool isvalid(int d,vector<int>& v,int m,int k){
        int ct=0,temp=0;
        for(auto& x:v){
            if(x<=d){
                temp++;

                if(temp==k){
                    ct++;
                    temp=0;
                }
            }
            else{
                if(temp==k)ct++;
                temp=0;
            }
        }
        if(temp==k)ct++;
        return (ct>=m);
    }
    int minDays(vector<int>& v, int m, int k) {
        int n=v.size();
        if(1LL*m*k>1LL*n)return -1;

        int l=1,r=INT_MIN,mid,ans;
        for(auto& x:v)r=max(r,x);
        ans=r;
        while(l<=r){
            mid=l+(r-l)/2;

            if(isvalid(mid,v,m,k)){
                ans=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }
};