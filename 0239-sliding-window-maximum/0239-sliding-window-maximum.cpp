class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& v, int k) {
        deque<int>dq;
        vector<int>ans;
        int i=0;
        for(int j=0;j<v.size();j++){
            while(!dq.empty() and v[dq.back()]<v[j]){
                dq.pop_back();
            }
            dq.push_back(j);


            if(j-i+1>k){
                if(i==dq.front()){
                    dq.pop_front();
                }
                i++;
            }

            if(j-i+1==k){
                ans.push_back(v[dq.front()]);
            }
        }
        return ans;
    }
};