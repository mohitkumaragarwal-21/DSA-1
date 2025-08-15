class Solution {
public:
    bool isPowerOfFour(int n) {
         
         vector<long long >v(16,0);
         for(int i=0;i<16;i++)
         {
             v[i] = (int(pow(4,i)));
         }

         for(int i=0;i<16;i++)
         {
             if(v[i]==n)
             return true;
         }

         return false;
    }
};