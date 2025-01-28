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

        int val = subRoot->val;

        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* temp = q.front();
            q.pop();

            if (temp->val == val) {
                bool same = helper(subRoot, temp);

                if (same) return true;
            }

            if (temp->left) q.push(temp->left);
            if (temp->right) q.push(temp->right);
        }
        return false;
    }
};