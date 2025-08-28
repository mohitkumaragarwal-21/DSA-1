class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
           int n = grid.size();

    // process each diagonal starting from first column and first row
    for (int start = 0; start < n; start++) {
        for (int fromRow = 0; fromRow < 2; fromRow++) {
            int i = fromRow ? 0 : start;
            int j = fromRow ? start : 0;
            if (i >= n || j >= n) continue;

            vector<int> diag;
            int x = i, y = j;

            // collect
            while (x < n && y < n) {
                diag.push_back(grid[x][y]);
                x++, y++;
            }

            // sort (decide order by i>=j condition)
            if (i >= j) 
                sort(diag.begin(), diag.end(), greater<int>()); // bottom-left
            else 
                sort(diag.begin(), diag.end()); // top-right

            // put back
            x = i, y = j;
            int idx = 0;
            while (x < n && y < n) {
                grid[x][y] = diag[idx++];
                x++, y++;
            }
        }
    }
    return grid;
    }
};