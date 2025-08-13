class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {

      using frac = tuple<double, int, int>; // (value, numerator, denominator)
    priority_queue<frac, vector<frac>, greater<frac>> pq;

    int n = arr.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            double val = (double)arr[i] / arr[j];
            pq.push({val, arr[i], arr[j]});
        }
    }

    while (--k) pq.pop();
    auto [val, num, den] = pq.top();
    return {num, den};
    }
};