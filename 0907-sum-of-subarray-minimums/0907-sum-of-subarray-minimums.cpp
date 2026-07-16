class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        int M=1000000007;
        vector<int> pf(n),sf(n);
        stack<int>st1,st2;
        st1.push(0);
        pf[0]=-1;
        for(int i=1;i<n;i++){
            while(!st1.empty() and arr[st1.top()]>arr[i]){
                st1.pop();
            }
            if(st1.empty())pf[i]=-1;
            else pf[i]=st1.top();

            st1.push(i);
        }

        st2.push(n-1);
        sf[n-1]=n;
        for(int i=n-2;i>=0;i--){
            while(!st2.empty() and arr[st2.top()]>=arr[i]){
                st2.pop();
            }
            if(st2.empty())sf[i]=n;
            else sf[i]=st2.top();

            st2.push(i);
        }

        long long ans=0;
        for(int i=0;i<n;i++){
            int k=pf[i],j=sf[i];
            int m=j-k-1;

            long long temp=((j-i)*1LL*(i-k))*1LL*(arr[i]);
            ans=(ans+(temp)%M)%M;
        }
        return ans;
    }
};