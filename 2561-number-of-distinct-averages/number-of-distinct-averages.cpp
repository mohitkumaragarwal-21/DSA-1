class Solution {
public:
    int distinctAverages(vector<int>& nums) {
        unordered_set<double>s;
        sort(nums.begin(), nums.end());

        int i=0, j = nums.size()-1;

        while(i<j)
        {
             int a = nums[i];
             int b = nums[j];
             
             if(a !=b){
             double ans = double((a+b)/2.0);
             s.insert(ans);
             i++;
             j--;
             }

             else
             {  
                s.insert(double(nums[i]));
                  i++;
             }
        }

        return s.size();
    }
};