class Solution {
public:
    int incremovableSubarrayCount(vector<int>& nums) {
        int n = nums.size();
        vector<bool> prefixOK(n+1, true); // prefixOK[i] = is nums[0..i-1] strictly increasing
        vector<bool> suffixOK(n+1, true); // suffixOK[i] = is nums[i..n-1] strictly increasing
        
        // Compute prefixOK
        for (int i = 1; i < n; i++) {
            prefixOK[i] = prefixOK[i-1] && (nums[i] > nums[i-1]);
        }
        prefixOK[n] = prefixOK[n-1]; // whole array check
        
        // Compute suffixOK
        for (int i = n-2; i >= 0; i--) {
            suffixOK[i] = suffixOK[i+1] && (nums[i] < nums[i+1]);
        }
        
        int count = 0;
        // Iterate over all subarrays [l,r]
        for (int l = 0; l < n; l++) {
            for (int r = l; r < n; r++) {
                // prefix part: nums[0..l-1]
                bool pre = (l == 0) ? true : prefixOK[l-1];
                // suffix part: nums[r+1..n-1]
                bool suf = (r == n-1) ? true : suffixOK[r+1];
                
                if (!pre || !suf) continue;
                
                // check boundary condition if both prefix and suffix exist
                if (l > 0 && r < n-1) {
                    if (!(nums[l-1] < nums[r+1])) continue;
                }
                
                count++;
            }
        }
        return count;
    }
};