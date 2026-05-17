class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int D) {
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX)); 
        for(int i = 0; i < n; i++)dist[i][i] = 0;
        for(auto& v:edges){
            dist[v[0]][v[1]]=v[2];
            dist[v[1]][v[0]]=v[2];
        }
        for(int k = 0; k < n; k++) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    if(dist[i][k] == INT_MAX || dist[k][j] == INT_MAX)
                        continue;

                    dist[i][j] = min(dist[i][j],
                                     dist[i][k] + dist[k][j]);
                }
            }
        }
        int val=INT_MAX,I=0;
        for(int i=0;i<n;i++){
            int tmp=0;
            for(auto& x:dist[i]){
                if(x<=D){
                    tmp++;
                }
            }
            if(tmp<=val){
                I=i;
                val=tmp;
            }
        }
        return I;  
    }
};