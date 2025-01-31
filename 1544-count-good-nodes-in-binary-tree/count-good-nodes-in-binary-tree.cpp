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

        int total = help(root->left, max) + help(root->right, max);

        return (root->val >= max) + total;
    }
public:
    int goodNodes(TreeNode* root) {
        return help(root, root->val);
    }
};