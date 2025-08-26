class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int area =0;
        double diagonalLength= 0.0;
          for(auto d:dimensions)
          {
                int p = d[0];
              int q = d[1];

              double n = sqrt(p*p + q*q);

              diagonalLength= max(diagonalLength,n);
          }
           for(auto d:dimensions)
           {
              int p = d[0];
              int q = d[1];

              double n = sqrt(p*p + q*q);
              if(n==diagonalLength)
              {  
              
                 area = max(area, p*q);
              }

           }

           return area;
    }
};