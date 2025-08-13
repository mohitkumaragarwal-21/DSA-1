class Solution {
public:
    bool isPowerOfThree(int n) {
        vector<long long>v(20,0);
        long long p =1;
        for( int i =0;i<20;i++)
        {    
            v[i] = p;
             p= p*3;

        }

        for(int i=0;i<20;i++)
        {
             if(v[i]==n && v[i]!=0)
             return true;
        }

        return false;
    }
};