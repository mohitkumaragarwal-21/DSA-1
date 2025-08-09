class Solution {
public:
    unordered_map<int, bool> memo;

    bool canWin(int maxInt, int target, int usedMask) {
        if (memo.count(usedMask)) return memo[usedMask];

        for (int i = 1; i <= maxInt; i++) {
            int bit = 1 << (i - 1);
            if ((usedMask & bit) == 0) { // if number i not used yet
                if (i >= target || !canWin(maxInt, target - i, usedMask | bit)) {
                    return memo[usedMask] = true;
                }
            }
        }
        return memo[usedMask] = false;
    }

    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        int sum = (maxChoosableInteger * (maxChoosableInteger + 1)) / 2;
        if (sum < desiredTotal) return false; // impossible to reach
        if (desiredTotal <= 0) return true;   // immediate win

        return canWin(maxChoosableInteger, desiredTotal, 0);
    }
};