class Solution {
public:
    int subarraySum(vector<int>& nums) {
        
    int n = nums.size();
    vector<int> prefix(n, 0);
    
    // Step 1: Build prefix sum
    prefix[0] = nums[0];
    for (int i = 1; i < n; i++) {
        prefix[i] = prefix[i - 1] + nums[i];
    }
    
    int totalSum = 0;
    
    // Step 2: For each i, find subarray sum using prefix sums
    for (int i = 0; i < n; i++) {
        int start = max(0, i - nums[i]);
        if (start == 0) {
            totalSum += prefix[i];
        } else {
            totalSum += prefix[i] - prefix[start - 1];
        }
    }
    
    return totalSum;
    }
};