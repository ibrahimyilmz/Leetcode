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
    int binaryTurbo(TreeNode* root, int& k) {
        if (!root) return -1;

        int l = binaryTurbo(root->left, k);
        k--;
        if (k == 0) return root->val;
        int r = binaryTurbo(root->right, k);

        if (l != -1) return l;
        return r;
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        return binaryTurbo(root, k);
    }
};