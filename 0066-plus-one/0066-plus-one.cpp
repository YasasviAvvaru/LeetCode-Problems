class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        reverse(digits.begin(),digits.end());
        vector<int>v=digits;
        int carry=1;
        for(int i=0;i<n;i++){
            if(carry==1 and carry+v[i]<=9){
                v[i]+=carry;
                break;
            }
            else if(carry==1 and v[i]==9){
                if(i==n-1){
                    v[i]=0;
                    v.push_back(1);
                }
                else{
                    v[i]=0;
                }
            }
            else{
                break;
            }
        }
        reverse(v.begin(),v.end());
        return v;
    }
};