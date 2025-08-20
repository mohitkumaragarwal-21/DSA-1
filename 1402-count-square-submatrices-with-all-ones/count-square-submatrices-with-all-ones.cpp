class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {

        // Using brute force
    //      int rows = matrix.size();
    // int cols = matrix[0].size();
    // int count = 0;

    // // loop over all possible top-left corners
    // for (int i = 0; i < rows; i++) {
    //     for (int j = 0; j < cols; j++) {
    //         // only start if the cell is 1
    //         if (matrix[i][j] == 1) {
    //             int size = 1;
    //             while (i + size <= rows && j + size <= cols) {
    //                 bool valid = true;
    //                 // check the square of size `size`
    //                 for (int x = i; x < i + size; x++) {
    //                     for (int y = j; y < j + size; y++) {
    //                         if (matrix[x][y] == 0) {
    //                             valid = false;
    //                             break;
    //                         }
    //                     }
    //                     if (!valid) break;
    //                 }
    //                 if (valid) {
    //                     count++;
    //                     size++;
    //                 } else {
    //                     break;
    //                 }
    //             }
    //         }
    //     }
    // }

    // return count;

    // Using DP  
       int rows = matrix.size();
    int cols = matrix[0].size();
    int total = 0;

    vector<vector<int>> dp(rows, vector<int>(cols, 0));

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == 1) {
                if (i == 0 || j == 0) {
                    dp[i][j] = 1; // first row/col: only 1x1 squares
                } else {
                    dp[i][j] = 1 + min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
                }
                total += dp[i][j];
            }
        }
    }

    return total;
    }
};