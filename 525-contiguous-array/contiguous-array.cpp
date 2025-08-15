class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int sum = 0, maxLen = 0;
    unordered_map<int, int> seen{{0, -1}}; // sum → first index it was seen
    
    for (int i = 0; i < nums.size(); i++) {
        // Treat 0 as -1, 1 as +1
        sum += nums[i] == 1 ? 1 : -1;

        if (seen.count(sum)) {
            // sum seen before → subarray between first occurrence and i has sum 0
            maxLen = max(maxLen, i - seen[sum]);
        } else {
            // store first time this sum is seen
            seen[sum] = i;
        }
    }
    return maxLen;
    }
};