class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
          vector<vector<int>>result(m,vector<int>(n,0));
            if (m * n != original.size()) {
            return {}; 
        }
          
          for(int i=0;i<m;i++)
          {
             result[i] = vector<int>(original.begin() + i * n, original.begin() + i * n + n);
          }

        
          return result;

          
    }
};