class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        
    // Note No.1 : Here , the sum idea will not work 
    int n = matrix.size();

    unordered_map<int , int>mp;
    for(int i=1;i<=n;i++)
    mp[i]++;

    for(int i=0;i<n;i++)
    {
          unordered_map<int , int>mpp;
          for(int j =0;j<n;j++)
          {
              mpp[matrix[i][j]]++;
          }

          if(mpp.size()!= mp.size())
          return false;
    }

     for(int j=0;j<n;j++)
    {
          unordered_map<int , int>mpp;
          for(int i =0;i<n;i++)
          {
               mpp[matrix[i][j]]++;
          }

          if(mpp.size()!= mp.size())
          return false;
    }

    return true;




         

    }
};