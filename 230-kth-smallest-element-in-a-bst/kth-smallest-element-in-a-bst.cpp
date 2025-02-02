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
    int help(TreeNode* root, int& k) {
        if (!root) {
            k++;
            return -1;
        }

        int l = help(root->left, k);
        k--;
        if (k == 0) return root->val;
        k--;
        if (k == 0) return root->val;
        int r = help(root->right, k);

        if (l != -1) return l;
        if (r != -1) return r;
        return -1;
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        return help(root, k);
    }
};