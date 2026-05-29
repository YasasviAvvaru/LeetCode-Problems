class Solution {
public:
    int myAtoi(string s) {
        int i=0;
        int sign;
        long long val=0;
        while(i<s.size()){
            if(s[i]!=' ')break;
            else i++;
        }
        if(i==s.size())return 0;
        
        if(s[i]=='-'){
            sign=-1;
            i++;
            while(i<s.size()){
                if(val<=INT_MIN){
                    return INT_MIN;
                }
                if('0'<=s[i] and s[i]-'0'<10){
                    val=10*val-(long long)(s[i]-'0');
                    i++;
                }
                else return val;
            }
        }
        else{
            sign=1;
            if(s[i]=='+')i++;
            while(i<s.size()){
                if(val>=INT_MAX){
                    return INT_MAX;
                }
                if('0'<=s[i] and s[i]-'0'<10){
                    val=10*val+(long long)(s[i]-'0');
                    i++;
                }
                else return val;
            }
        }
        if(val<=INT_MIN)return INT_MIN;
        if(val>=INT_MAX)return INT_MAX;
        return val;
        
    }
};