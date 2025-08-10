class Solution {
public:
    bool reorderedPowerOf2(int n) {
           
         vector<long long> v(32, 0);
    for (int i = 0; i < 32; i++) {
        v[i] = pow(2, i);
    }

    unordered_map<int, int> mp;
    int t = n;
    if (t == 0) mp[0]++;
    while (t > 0) {
        int digit = t % 10;
        mp[digit]++;
        t /= 10;
    }

    for (int i = 0; i < 32; i++) {
        unordered_map<int, int> m;
        int num = v[i];
        if (num == 0) m[0]++;
        while (num > 0) {
            int digit = num % 10;
            m[digit]++; // ✅ fixed from m[num]++
            num /= 10;
        }

        bool same = true;
        for (auto &p : mp) { // ✅ fixed comparison
            if (m[p.first] != p.second) {
                same = false;
                break;
            }
        }

        if (same && mp.size() == m.size()) { // ✅ check both maps match exactly
            return true;
        }
    }

    return false;
    }
};