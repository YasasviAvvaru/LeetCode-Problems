class Solution {
public:
    string largestOddNumber(string num) {
        while(!num.empty()){
            if((num.back()-'0')%2==0){
                num.pop_back();
            }
            else return num;
        }
        return num;
    }
};