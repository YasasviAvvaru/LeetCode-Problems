class Solution {
public:
    int searchInsert(vector<int>& v, int x) {
        int count = upper_bound(v.begin(), v.end(), x)- lower_bound(v.begin(), v.end(), x);

        auto it = lower_bound(v.begin(), v.end(), x);
        return it-v.begin();

    }
};