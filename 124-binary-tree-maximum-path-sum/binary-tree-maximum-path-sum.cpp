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
    int max;
    int help(TreeNode* root, int curr, int& max) {
        if (!root) return 0;

        int l = help(root->left, curr, max);
        int r = help(root->right, curr, max);

        curr = l + r + root->val;
        max = std::max(max, curr);

        if (curr < 0) curr = 0;
        else curr -= min(l, r);

        return curr;
    }
public:
    int maxPathSum(TreeNode* root) {
        max = root->val;
        help(root, 0, max);
        return max;
    }
};