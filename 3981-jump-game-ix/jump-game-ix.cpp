class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
             vector<int> ans = nums;
        vector<pair<int, int>> greatesttoleft(nums.size(), {-1, -1});
        vector<pair<int, int>> smallesttoright(nums.size(), {-1, -1});

        pair<int, int> maxi = {nums[0], 0};
        for (int i = 1; i < nums.size(); i++) {
            greatesttoleft[i] = maxi;
            if (nums[i] > maxi.first) {
                maxi.first = nums[i];
                maxi.second = i;
            }
        }
        maxi = {nums[nums.size() - 1], nums.size() - 1};

        for (int i = nums.size() - 2; i >= 0; i--) {
            smallesttoright[i] = maxi;
            if (nums[i] < maxi.first) {
                maxi.first = nums[i];
                maxi.second = i;
            }
        }

        for (int i = nums.size() - 1; i >= 0; i--) {
            if (greatesttoleft[i].first > ans[i])
                ans[i] = greatesttoleft[i].first;
             if (smallesttoright[i].first != -1 &&
                     smallesttoright[i].first < ans[i]) {
                if (ans[smallesttoright[i].second] > ans[i])
                    ans[i] = ans[smallesttoright[i].second];
            }
        }
        return ans;   
    }
};