class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& v) {

        sort(v.begin(), v.end());

        int ct = 0;

        int r = v[0][1];

        for(int i = 1; i < v.size(); i++) {

            if(v[i][0] < r) {   // overlap
                ct++;

                // keep interval with smaller end
                r = min(r, v[i][1]);
            }
            else {
                r = v[i][1];
            }
        }

        return ct;
    }
};