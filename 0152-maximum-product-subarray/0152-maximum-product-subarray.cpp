class Solution {
public:
    //no 0's involved.
    int fxn(vector<int>& v){
        int st=0,end=0,ct=0;
        for(auto& x:v){
            if(x<0)ct++;
        }
        int ans=1;
        int ans2=1;
        for(int i=0;i<v.size();i++){
                ans2=ans2*v[i];
        }
        if(ct%2==0){
            return ans2;
        }
        else{
            int ans1=1;
            if(v.size()==1)return v[0];
            for(int i=0;i<v.size();i++){
                if(v[i]<0){
                    st=i;
                    break;
                }
                else ans=ans*v[i];
            }
            
            ans=max(ans,ans2/(ans*v[st]));
            for(int i=v.size()-1;i>=0;i--){
                if(v[i]<0){
                    end=i;
                    break;
                }
                else ans1=ans1*v[i];
            }
            
            ans1=max(ans1,ans2/(ans1*v[end]));
            ans=max(ans,ans1);

            return ans;
        }
    }   
    int maxProduct(vector<int>& nums) {
        int ans=INT_MIN;
        vector<int>temp;
        for(auto& x:nums){
            ans=max(ans,x);
        }
        for(auto& x:nums){
            if(x!=0){
                temp.push_back(x);
            }
            else if(temp.size()>0){
                int t=fxn(temp);
                ans=max(ans,t);
                temp.clear();
            }
        }
        if(temp.size()>0){
            int t=fxn(temp);
                ans=max(ans,t);
                temp.clear();
        }
        return ans;
    }
};