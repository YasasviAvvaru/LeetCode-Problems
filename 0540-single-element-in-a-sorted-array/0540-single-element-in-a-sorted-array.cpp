class Solution {
public:
    int singleNonDuplicate(vector<int>& v) {
        //bool fxn -> the first val whose left of fst occ are odd.
        //ans= val-1.

        int l=0,r=v.size()-1,mid,ans=0;
        while(l<=r){
            int mid=(l+r)/2;
            int fst=mid;
            if(mid>0 and v[mid]==v[mid-1]){
                fst--;
            }

            if(fst%2!=0){
                ans=fst;
                r=fst-1;
            }
            else{
                if(fst==v.size()-1){
                    ans=fst;
                    break;
                }
                else if(v[fst]==v[fst+1]){
                    l=fst+2;
                }
                else{
                    ans=fst;
                    break;
                }
            }
        }
        return v[ans];


        // int n=v.size(),st=0,mid=0,end=n-1;
        // if(n==1)return v[0];
        // while(st<=end){
        //     mid=(st+end)/2;
            
        //     if(mid==0){
        //         if(v[mid]==v[1])st=2;
        //         else return v[0];
        //     }
        //     else if(mid==n-1){
        //         if(v[mid]==v[mid-1])end=mid-2;
        //         else return v[n-1];
        //     }
        //     else{
        //         if(v[mid]==v[mid+1]){
        //             if(mid%2==0)st=mid+2;
        //             else end=mid-1;
        //         }
        //         else if(v[mid]==v[mid-1]){
        //             if((mid+1)%2==0)st=mid+1;
        //             else end=mid-2;
        //         }
        //         else return v[mid];
        //     }
        // }
        // return end;
    }
};