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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;
        if (!(p && q)) return false;

        queue<TreeNode*> queP;
        queP.push(p);
        queue<TreeNode*> queQ;
        queQ.push(q);

        while(!queP.empty() && !queQ.empty()) {
            p = queP.front();
            queP.pop();
            q = queQ.front();
            queQ.pop();

            if (p->val != q->val) return false;

            if (p->right && !q->right || !p->right && q->right) return false;
            if (p->left && !q->left || !p->left && q->left) return false;

            if (p->right) queP.push(p->right);
            if (p->left) queP.push(p->left);

            if (q->right) queQ.push(q->right);
            if (q->left) queQ.push(q->left); 
        }

        if (queP.empty() && queQ.empty()) return true;

        return false;
    }
};