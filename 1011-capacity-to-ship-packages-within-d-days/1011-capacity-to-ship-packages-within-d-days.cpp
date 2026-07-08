class Solution {
public:
    bool isvalid(int w,vector<int>& v,int d){
        int ct=0,temp=0;
        for(auto& x:v){
            if(temp+x<=w){
                temp+=x;
            }
            else{
                ct++;
                temp=x;
            }
        }
        if(temp>0)ct++;
        return ct<=d;
    }
    int shipWithinDays(vector<int>& v, int d) {
        int l=INT_MIN,r=0,mid,ans;
        for(auto& x:v){r+=x;l=max(l,x);}
        ans=r;
        while(l<=r){
            mid=l+(r-l)/2;

            if(isvalid(mid,v,d)){
                ans=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }
};