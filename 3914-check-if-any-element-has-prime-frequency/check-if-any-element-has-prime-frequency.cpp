class Solution {
public: 

  bool isPrime(int n)
  {
     

      if(n==1)
      return false;

      for(int i=2;i*i<=n;i++)
      {

        if(n%i ==0)
        return false;
      }

      return true;
  }
    bool checkPrimeFrequency(vector<int>& nums) {
          unordered_map<int, int>mp;
          for(int i=0;i<nums.size();i++)
          mp[nums[i]]++;

          for(auto num :mp)
          {
             
             int freq = num.second;

             if(isPrime(freq))
             return true;
          }

          return false;
    }
};