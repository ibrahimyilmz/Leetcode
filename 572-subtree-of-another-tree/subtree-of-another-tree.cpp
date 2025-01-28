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
    bool helper(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;
        if (!p || !q) return false;
        if (p->val != q->val) return false;

        bool l = helper(p->left, q->left);
        bool r = helper(p->right, q->right);

        return l && r;
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root && !subRoot) return true;
        if (!root && subRoot) return false;

        if (root->val == subRoot->val) {
            bool same = helper(subRoot, root);
            
            if (same) return true;
        }

        bool l = isSubtree(root->left, subRoot);
        bool r = isSubtree(root->right, subRoot);

        return l || r;
    }
};