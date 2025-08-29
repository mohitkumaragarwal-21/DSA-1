class Solution {
public:
    int smallestRepunitDivByK(int k) {
         if(k%2==0||k%5==0){
        return -1;
    }
    int number=0;
    for(int N=1;N<=k;N++){
        number=((number*10+1)%k);
        if(number==0){
            return N;
        }
    }
    return -1;
    }
};