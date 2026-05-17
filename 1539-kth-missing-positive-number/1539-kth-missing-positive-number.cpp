class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int i=0,ct=0,val=1;
        while(ct<k and i<arr.size()){
            if(arr[i]==val){
                val++;
                i++;
            }
            else{
                val++;
                ct++;
            }
        }
        if(i==arr.size())return val+k-1-ct;
        return val-1;
    }
};