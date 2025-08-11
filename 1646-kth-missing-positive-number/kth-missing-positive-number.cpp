class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
         vector<int> v(2001, 0); // bigger size to handle larger missing numbers
    for (int i = 0; i < arr.size(); i++) {
        v[arr[i]] = 1; // mark the numbers present
    }

    int ans = 0;
    for (int i = 1; i < v.size(); i++) {
        if (v[i] == 0) { // missing number
            ans = i;
            k--;
            if (k == 0) return ans;
        }
    }

    // if not found in v[] range, continue beyond
    int i = v.size();
    while (k > 0) {
        ans = i;
        i++;
        k--;
    }
    return ans;

    }
};