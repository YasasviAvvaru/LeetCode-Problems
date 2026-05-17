class Solution {
public:
    int singleNonDuplicate(vector<int>& v) {
        int n=v.size(),st=0,mid=0,end=n-1;
        if(n==1)return v[0];
        while(st<=end){
            mid=(st+end)/2;
            
            if(mid==0){
                if(v[mid]==v[1])st=2;
                else return v[0];
            }
            else if(mid==n-1){
                if(v[mid]==v[mid-1])end=mid-2;
                else return v[n-1];
            }
            else{
                if(v[mid]==v[mid+1]){
                    if(mid%2==0)st=mid+2;
                    else end=mid-1;
                }
                else if(v[mid]==v[mid-1]){
                    if((mid+1)%2==0)st=mid+1;
                    else end=mid-2;
                }
                else return v[mid];
            }
        }
        return end;
    }
};