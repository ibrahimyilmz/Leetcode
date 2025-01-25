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
    int maxDepth(TreeNode* root) {
        if (!root) return 0;

        int l = maxDepth(root->left);
        int r = maxDepth(root->right);

        return max(l, r) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if (!root) return 0;

        stack<TreeNode*> st;
        st.push(root);
        int res = 0;
        while (!st.empty()) {
            TreeNode* temp = st.top();
            st.pop();

            int l = maxDepth(temp->left);
            int r = maxDepth(temp->right);

            res = max(res, l + r);

            if (temp->left) st.push(temp->left);
            if (temp->right) st.push(temp->right);
        }
        return res;
    }
};