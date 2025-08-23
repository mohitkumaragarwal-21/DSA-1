class Solution {
public:
const int INF = 1e9;

// Function to compute bounding box area of all 1's in a submatrix
int boundingBoxArea(const vector<vector<int>>& grid, int r1, int c1, int r2, int c2) {
    int minr = INF, maxr = -INF, minc = INF, maxc = -INF;
    for (int i = r1; i <= r2; i++) {
        for (int j = c1; j <= c2; j++) {
            if (grid[i][j] == 1) {
                minr = min(minr, i);
                maxr = max(maxr, i);
                minc = min(minc, j);
                maxc = max(maxc, j);
            }
        }
    }
    if (minr == INF) return INF; // no 1's found
    return (maxr - minr + 1) * (maxc - minc + 1);
}
    int minimumSum(vector<vector<int>>& grid) {
         int m = grid.size(), n = grid[0].size();
        int ans = INF;

        // 1) Horizontal partitions
        for (int i = 0; i < m - 2; i++) {
            for (int j = i + 1; j < m - 1; j++) {
                int a = boundingBoxArea(grid, 0, 0, i, n - 1);
                int b = boundingBoxArea(grid, i + 1, 0, j, n - 1);
                int c = boundingBoxArea(grid, j + 1, 0, m - 1, n - 1);
                if (a != INF && b != INF && c != INF)
                    ans = min(ans, a + b + c);
            }
        }

        // 2) Vertical partitions
        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                int a = boundingBoxArea(grid, 0, 0, m - 1, i);
                int b = boundingBoxArea(grid, 0, i + 1, m - 1, j);
                int c = boundingBoxArea(grid, 0, j + 1, m - 1, n - 1);
                if (a != INF && b != INF && c != INF)
                    ans = min(ans, a + b + c);
            }
        }

        // 3) L-shaped partitions
        for (int row = 0; row < m - 1; row++) {
            for (int col = 0; col < n - 1; col++) {
                {
                    int a = boundingBoxArea(grid, 0, 0, row, col);
                    int b = boundingBoxArea(grid, 0, col + 1, row, n - 1);
                    int c = boundingBoxArea(grid, row + 1, 0, m - 1, n - 1);
                    if (a != INF && b != INF && c != INF)
                        ans = min(ans, a + b + c);
                }
                {
                    int a = boundingBoxArea(grid, 0, 0, row, n - 1);
                    int b = boundingBoxArea(grid, row + 1, 0, m - 1, col);
                    int c = boundingBoxArea(grid, row + 1, col + 1, m - 1, n - 1);
                    if (a != INF && b != INF && c != INF)
                        ans = min(ans, a + b + c);
                }
                {
                    int a = boundingBoxArea(grid, 0, 0, row, col);
                    int b = boundingBoxArea(grid, row + 1, 0, m - 1, col);
                    int c = boundingBoxArea(grid, 0, col + 1, m - 1, n - 1);
                    if (a != INF && b != INF && c != INF)
                        ans = min(ans, a + b + c);
                }
                {
                    int a = boundingBoxArea(grid, 0, col + 1, row, n - 1);
                    int b = boundingBoxArea(grid, row + 1, col + 1, m - 1, n - 1);
                    int c = boundingBoxArea(grid, 0, 0, m - 1, col);
                    if (a != INF && b != INF && c != INF)
                        ans = min(ans, a + b + c);
                }
            }
        }

        return (ans == INF ? -1 : ans);  
    }
};