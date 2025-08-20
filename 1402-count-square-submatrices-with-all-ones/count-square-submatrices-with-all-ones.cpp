class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
         int rows = matrix.size();
    int cols = matrix[0].size();
    int count = 0;

    // loop over all possible top-left corners
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            // only start if the cell is 1
            if (matrix[i][j] == 1) {
                int size = 1;
                while (i + size <= rows && j + size <= cols) {
                    bool valid = true;
                    // check the square of size `size`
                    for (int x = i; x < i + size; x++) {
                        for (int y = j; y < j + size; y++) {
                            if (matrix[x][y] == 0) {
                                valid = false;
                                break;
                            }
                        }
                        if (!valid) break;
                    }
                    if (valid) {
                        count++;
                        size++;
                    } else {
                        break;
                    }
                }
            }
        }
    }

    return count;  
    }
};