class Solution {
public:  
 
 int solve(int n ,  unordered_map<int, int>&dp)
 {
      // base case
      if(n==0 || n==1)
      return 1;

      if(dp.find(n) == dp.end())
      {
          dp[n] = solve(n-1,dp) +  solve(n-2,dp);
      }

      return dp[n];
 }
    int climbStairs(int n) {
         // Method 1: Brute force using recursion

        //  if(n==0 || n==1)
        //  return 1;   // 1 way to climb the stair not the steps taken 

        //  return climbStairs(n-1) + climbStairs(n-2);


        // Method 2:  Memoization method 

        // unordered_map<int , int> dp;
        // return solve(n,dp);

        // Method 3: Tabulation - Bottom Up approach 
         
         if(n==0|| n==1)
         return 1;

         vector<int>dp(n+1,0);

         dp[0]=1, dp[1]=1;

         for(int i=2;i<=n;i++)
         {
              dp[i] = dp[i-1]+dp[i-2];
         }

        return  dp[n];
    }
};