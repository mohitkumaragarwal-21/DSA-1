class Solution {
public:
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int n = fruits.size(), child1, child2, child3;
        child1 = 0;
        for(int i = 0; i < n; ++i){
            child1 += fruits[i][i];
            fruits[i][i] = 0;
        }
        for(int i = n - 1; i >= 0; --i){
            for(int j = n - 1; j >= 0; --j){
                if(j == i)
                    break;
                fruits[i][j] += max(fruits[i + 1][j], max(j - 1 > i + 1 ? fruits[i + 1][j - 1] : 0, j + 1 < n ? fruits[i + 1][j + 1] : 0));
            }
        }
        for(int j = n - 1; j >= 0; --j){
            for(int i = n - 1; i >= 0; --i){
                if(i == j)
                    break;
                fruits[i][j] += max(fruits[i][j + 1], max(j + 1 < i - 1 ? fruits[i - 1][j + 1] : 0, i + 1 < n ? fruits[i + 1][j + 1] : 0));
            }
        }
        return child1 + fruits[0][n - 1]  + fruits[n - 1][0] ;
    }
};