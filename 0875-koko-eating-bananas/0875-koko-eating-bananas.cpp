class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int end=INT_MIN,st=1,mid=0;
        for(auto& x:piles){
            end=max(x,end);
        }
        while(st<=end){
            mid=(st+end)/2;
            
            long long val=0;
            for(auto& x:piles){
                val+=(x+mid-1)/mid;
            }
            if(val<=h)end=mid-1;
            else st=mid+1;
        }
        return st;
    }
};