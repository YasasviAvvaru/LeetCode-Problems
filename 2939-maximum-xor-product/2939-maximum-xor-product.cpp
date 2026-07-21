typedef long long ll;
class Solution {
public:
    const ll mod = (ll)(1e9 +7);
    int maximumXorProduct(long long a, long long b, int n) {
        for (ll i = n - 1; i >= 0; i--) {
            ll bit = (ll)(1) << i;
            if ((bit & a) == (bit & b)) {
                a = a | bit;
                b = b | bit;
            } else {
                if (a > b) swap(a, b);
                a = a | bit;
                b = b & (~bit);
            }
        }
        return ((a % mod) * (b % mod)) % mod; 
    }
};