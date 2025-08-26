class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
         int area = 0;
    double maxDiagonal = 0.0;

    for (auto &d : dimensions) {
        int p = d[0], q = d[1];
        double diag = sqrt(1.0 * p * p + 1.0 * q * q);

        if (diag > maxDiagonal) {
            maxDiagonal = diag;
            area = p * q;
        } 
        else if (diag == maxDiagonal) {
            area = max(area, p * q);
        }
    }

    return area;
    }
};