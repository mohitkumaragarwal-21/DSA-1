class Solution {
public:
typedef long long ll;

long long minOperations(vector<vector<int>>& queries) {
    ll ans = 0;

    for (auto &q : queries) {
        ll start = q[0];
        ll end = q[1];
        ll operations = 0;

        ll bound = 1;
        for (int cost = 1; cost < 18; cost++) {
            if (bound > end) break;
            ll nextBound = bound * 4LL;

            ll l = max(start, bound);
            ll r = min(end, nextBound - 1);

            if (r >= l) {
                operations += (r - l + 1) * cost;
            }

            bound = nextBound;
        }

        ans += (operations + 1) / 2;  // ceil division
    }

    return ans;
}
};