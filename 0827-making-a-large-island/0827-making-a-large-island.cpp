class Solution {
public:

    int n;

    vector<vector<pair<int,int>>> parent;
    vector<vector<int>> sz;

    pair<int,int> find(pair<int,int> p){

        int x = p.first;
        int y = p.second;

        if(parent[x][y] == p)
            return p;

        return parent[x][y] = find(parent[x][y]);
    }

    void unite(pair<int,int> a, pair<int,int> b){

        a = find(a);
        b = find(b);

        if(a == b) return;

        if(sz[a.first][a.second] < sz[b.first][b.second])
            swap(a,b);

        parent[b.first][b.second] = a;

        sz[a.first][a.second] += sz[b.first][b.second];
    }

    int largestIsland(vector<vector<int>>& grid) {

        n = grid.size();

        parent.resize(n, vector<pair<int,int>>(n));
        sz.assign(n, vector<int>(n,1));

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                parent[i][j] = {i,j};
            }
        }

        int dx[4] = {1,-1,0,0};
        int dy[4] = {0,0,1,-1};

        // Build DSU
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){

                if(grid[i][j] == 1){

                    for(int k=0;k<4;k++){

                        int nx = i + dx[k];
                        int ny = j + dy[k];

                        if(nx>=0 && ny>=0 && nx<n && ny<n
                           && grid[nx][ny]==1){

                            unite({i,j}, {nx,ny});
                        }
                    }
                }
            }
        }

        int ans = 0;

        bool hasZero = false;

        // Try flipping each 0
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){

                if(grid[i][j] == 0){

                    hasZero = true;

                    set<pair<int,int>> comps;

                    for(int k=0;k<4;k++){

                        int nx = i + dx[k];
                        int ny = j + dy[k];

                        if(nx>=0 && ny>=0 && nx<n && ny<n
                           && grid[nx][ny]==1){

                            comps.insert(find({nx,ny}));
                        }
                    }

                    int curr = 1;

                    for(auto p : comps){

                        curr += sz[p.first][p.second];
                    }

                    ans = max(ans, curr);
                }
            }
        }

        // all 1s case
        if(!hasZero)
            return n*n;

        return ans;
    }
};