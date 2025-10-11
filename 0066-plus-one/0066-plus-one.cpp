class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        reverse(digits.begin(),digits.end());
        int carry=1;
        for(int i=0;i<n;i++){
            if(carry==1 and digits[i]<9){
                digits[i]+=carry;
                break;
            }
            else if(carry==1 and digits[i]==9){
                if(i==n-1){
                    digits[i]=0;
                    digits.push_back(1);
                }
                else{
                    digits[i]=0;
                }
            }
            else{
                break;
            }
        }
        reverse(digits.begin(),digits.end());
        return digits;
    }
};