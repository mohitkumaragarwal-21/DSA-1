class Solution {
public:
    vector<int> circularGameLosers(int n, int k) {
         vector<int> visited(n, 0);  // 0-based
    int pos = 0;  // player 1 at index 0
    int step = 1;

    while (!visited[pos]) {
        visited[pos] = 1;
        pos = (pos + step * k) % n;
        step++;
    }

    vector<int> ans;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) ans.push_back(i + 1); // convert back to 1-based
    }
    return ans;
    }
    
};