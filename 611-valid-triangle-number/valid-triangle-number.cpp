class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        // Step 1: Sort the array
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        int count = 0;

        // Step 2: Iterate through the array, fixing the largest side
        for (int k = n - 1; k >= 2; k--) {
            int i = 0, j = k - 1;

            // Step 3: Use two pointers to find valid pairs
            while (i < j) {
                if (nums[i] + nums[j] > nums[k]) {
                    // All pairs between i and j are valid
                    count += (j - i);
                    j--; // Move the right pointer left
                } else {
                    i++; // Move the left pointer right
                }
            }
        }

        return count;
    }
};