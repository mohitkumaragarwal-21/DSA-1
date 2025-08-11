class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
          
          //Approach 1: Using brute force approach  T.C= O(n*n)
        //   int p=0;
        //   for(int i=0;i<nums.size();i++)
        //   {
        //      for(int j = i+1;j<nums.size();j++)
        //      {
        //           if(nums[i]+nums[j]<target)
        //           {
        //              p++;
        //           }
        //      }
        //   }

        //   return p;

        // Coming to the optimal approach
           sort(nums.begin(), nums.end());
    int n = nums.size();
    long long count = 0;

    for (int i = 0; i < n; i++) {
        int needed = target - nums[i]; // nums[j] < needed
        auto it = lower_bound(nums.begin() + i + 1, nums.end(), needed);
        int j = it - nums.begin();
        count += (j - (i + 1));
    }

    return count;
    }
};