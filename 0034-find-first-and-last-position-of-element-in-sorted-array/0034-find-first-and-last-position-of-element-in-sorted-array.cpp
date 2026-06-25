class Solution {
public:
    bool isvalid(int val,int x){return val>=x;}
    int fstocc(vector<int>& v,int x){
        int l=0,r=v.size()-1,mid,ans=-1;

        while(l<=r){
            mid=(l+r)/2;

            if(isvalid(v[mid],x)){
                ans=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        if(ans>=0 and ans<=v.size()-1 and v[ans]==x)return ans;
        else return -1;
    }
    int gtexist(vector<int>& v,int x){
        int l=0,r=v.size()-1,mid,ans=v.size();

        while(l<=r){
            mid=(l+r)/2;

            if(isvalid(v[mid],x)){
                ans=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& v, int x){
        //starting idx = first occurence of target.
        //ending idx = last occurence of target
        // = (first occ of target+1) - 1  
        int st=fstocc(v,x);
        int end=gtexist(v,x+1)-1;

        end=max(end,-1);
        if(st==-1)return {-1,-1};
        return {st,end};

        // auto it1= lower_bound(v.begin(),v.end(),x)-v.begin();
        // auto it2=upper_bound(v.begin(),v.end(),x)-v.begin();

        // int ct=it2-it1;
        // if(ct==0)return {-1,-1};
        // else return {(int)it1,(int)(it2-1)};
    }
};