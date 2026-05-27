class Solution {
public:
    int subarraySum(vector<int>& v, int k) {
        int n = v.size();

        vector<int> pf(n + 1, 0);

        for(int i = 0; i < n; i++) {
            pf[i + 1] = pf[i] + v[i];
        }

        unordered_map<int, vector<int>> pos;

        for(int j = 0; j <= n; j++) {
            pos[pf[j]].push_back(j);
        }

        int ct = 0;

        for(int i = 0; i < n; i++) {

            auto &z = pos[pf[i] + k];

            ct += z.end() - upper_bound(z.begin(), z.end(), i);
        }

        return ct;
    }
};