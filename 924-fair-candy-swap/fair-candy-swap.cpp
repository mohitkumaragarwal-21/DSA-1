class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
         
         int sumOfAlice = 0;
         int sumOfBob = 0;

         for(auto num:aliceSizes)
         {
             sumOfAlice+= num;
         }

         for(auto num:bobSizes)
         {
             sumOfBob+= num;
         }
     
     int target = (sumOfBob - sumOfAlice)/2;
          unordered_set<int> bobSet(bobSizes.begin(), bobSizes.end());

    for (int x : aliceSizes) {
        int y = x + target;
        if (bobSet.count(y)) {
            return {x, y};
        }
    }

    return {};  

    }
};