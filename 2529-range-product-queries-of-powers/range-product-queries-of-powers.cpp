class Solution {
public:  
    vector<long long> v;

    bool solve(long long left, int start, vector<int>& powers) {
        if (left == 0) return true;
        if (start < 0) return false;

        for (int i = start; i >= 0; i--) {
            if (left >= v[i]) {
                powers.push_back(v[i]);
                if (solve(left - v[i], i - 1, powers))
                    return true;
                powers.pop_back();
            }
        }
        return false;
    }

    const long long MOD = 1e9 + 7;

    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        v.resize(32);
        for (int i = 0; i < 32; i++)
            v[i] = (1LL << i);

        vector<int> powers;
        for (int i = 31; i >= 0; i--) {  
            if (v[i] == n) {
                powers.push_back(v[i]);
                break;
            } else if (v[i] < n) {
                powers.push_back(v[i]);
                if (solve(n - v[i], i - 1, powers))
                    break;
                powers.pop_back();
            }
        }

        reverse(powers.begin(), powers.end());

        int m = queries.size();
        vector<int> res(m);
        for (int i = 0; i < m; i++) {
            int left = queries[i][0];
            int right = queries[i][1];
            long long p = 1;
            for (int j = left; j <= right; j++) {
                p = (p * powers[j]) % MOD;
            }
            res[i] = (int)p;
        }
        return res;
    }
};
