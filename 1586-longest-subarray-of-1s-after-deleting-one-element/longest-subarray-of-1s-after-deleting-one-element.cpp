class Solution {
public:
    int longestSubarray(vector<int>& nums) {
       int n = nums.size();
    int l = 0, maxlen = 0;
    int countZeroes = 0;

    for (int r = 0; r < n; r++) {
        if (nums[r] == 0) countZeroes++;

        // If more than 1 zero, shrink window
        while (countZeroes > 1) {
            if (nums[l] == 0) countZeroes--;
            l++;
        }

        // Update max length (delete one element, so length = r-l+1-1)
        maxlen = max(maxlen, r - l);
    }

    return maxlen;
    }
};