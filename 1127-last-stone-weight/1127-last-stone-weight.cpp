class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq;
        for(int i=0;i<stones.size();i++){
            pq.push(stones[i]);
        }
        int temp1,temp2;
        while(pq.size()>=2){
            temp1=pq.top();
            pq.pop();
            temp2=pq.top();
            if(temp1==temp2){
                pq.pop();
            }
            else{
                pq.pop();
                pq.push(abs(temp1-temp2));
            }
        }
        if(!pq.empty())return pq.top();
        return 0;
    }
};