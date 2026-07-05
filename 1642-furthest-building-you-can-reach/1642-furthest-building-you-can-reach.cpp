class Solution {
public:
    int furthestBuilding(vector<int>& ht, int nb, int nl) {
        vector<pair<int,int>>d;
        int n=ht.size();
        for(int i=0;i<n-1;i++){
            if(ht[i]<ht[i+1]){
                d.push_back({ht[i+1]-ht[i],i});
            }
        }
        int m=d.size();
        if(nl>=m)return n-1;
        else{
            multiset<int>ms;
        for(int i=0;i<nl;i++){
            ms.insert(d[i].first);
        }

        int i=nl;
        while(i<m){
            ms.insert(d[i].first);
            if(nb>=*ms.begin()){
                nb-=*ms.begin();
                ms.erase(ms.begin());
                i++;
            }
            else break;
        }
            if(i==m)return n-1;
            
            return d[i].second;
        }

    }
};