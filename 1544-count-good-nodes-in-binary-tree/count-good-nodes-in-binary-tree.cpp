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
private:
    int help(TreeNode* root, int max) {
        if (!root) return 0;

        max = std::max(root->val, max);

        int l = help(root->left, max);
        int r = help(root->right, max);

        if (root->val >= max) return l + r + 1;
        return l + r;
    }
public:
    int goodNodes(TreeNode* root) {
        return help(root, root->val);
    }
};