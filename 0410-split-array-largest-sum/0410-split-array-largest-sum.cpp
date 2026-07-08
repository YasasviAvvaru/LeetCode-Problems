class Solution {
public:
    bool valid(int s,vector<int>& v,int k){
        int temp=0,ct=0;
        for(auto& x:v){
            if(temp==s){
                ct++;
                temp=0;
            }
            //temp<s.
            if(temp+x>s){
                ct++;
                temp=x;
            }
            else temp+=x;
        }
        if(temp>0)ct++;
        return ct<=k;
    }
    int splitArray(vector<int>& v, int k) {
        int n=v.size();
        int l=INT_MIN,r=0,mid,ans;
        for(auto& x:v){
            r+=x;
            l=max(l,x);
        }
        ans=r;
        while(l<=r){
            mid=l+(r-l)/2;

            if(valid(mid,v,k)){
                ans=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }
};