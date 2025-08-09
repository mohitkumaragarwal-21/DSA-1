class Solution {
public:
    const long long MOD = 1e9 + 7;
    vector<vector<long long>> combs;

    long long dfs(vector<int> &arr) {
        if (arr.size() <= 2) return 1;
        int root = arr[0];

        vector<int> left, right;
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] < root) left.push_back(arr[i]);
            else right.push_back(arr[i]);
        }

        int l = left.size();
        int r = right.size();

        long long ways = combs[l + r][l];
        ways = (ways * dfs(left)) % MOD;
        ways = (ways * dfs(right)) % MOD;

        return ways;
    }

    int numOfWays(vector<int>& nums) {
        int n = nums.size();

        // Precompute Pascal's triangle
        combs.assign(n + 1, vector<long long>(n + 1, 0));
        for (int i = 0; i <= n; i++) {
            combs[i][0] = combs[i][i] = 1;
            for (int j = 1; j < i; j++) {
                combs[i][j] = (combs[i - 1][j - 1] + combs[i - 1][j]) % MOD;
            }
        }

        return (dfs(nums) - 1 + MOD) % MOD; // exclude original order
    }
};