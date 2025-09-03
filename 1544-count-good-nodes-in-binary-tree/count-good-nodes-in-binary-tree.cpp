/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
int helper(TreeNode* node, int maxSoFar) {
        if (node == nullptr) return 0;

        int good = 0;
        if (node->val >= maxSoFar) {
            good = 1; // current node is good
        }

        // Update maxSoFar for children
        maxSoFar = max(maxSoFar, node->val);

        // DFS left + right
        good += helper(node->left, maxSoFar);
        good += helper(node->right, maxSoFar);

        return good;
    }
    int goodNodes(TreeNode* root) {
         if (root == nullptr) return 0;
        return helper(root, root->val);
    }
};