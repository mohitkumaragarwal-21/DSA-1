class Solution {
public:
    bool isPowerOfTwo(int n) {
          if(n==1)
          return true;

          vector<long long>v(32,0);
          for(int i=0;i<32;i++)
          {
              v[i] = pow(2,i);
          }

          for(int i=0;i<32;i++)
          {
             if(n==abs(v[i]))
             return true;
          }

          return false;
    }
};