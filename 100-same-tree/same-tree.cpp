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

        stack<pair<TreeNode*, TreeNode*>> stk;
        stk.push({p, q});

        while (!stk.empty()) {
            auto nodePair = stk.top();
            stk.pop();

            TreeNode* nodeP = nodePair.first;
            TreeNode* nodeQ = nodePair.second;

            if (nodeP->val != nodeQ->val) return false;

            if (nodeP->left && nodeQ->left) {
                stk.push({nodeP->left, nodeQ->left});
            } else if (nodeP->left || nodeQ->left) {
                return false;
            }

            if (nodeP->right && nodeQ->right) {
                stk.push({nodeP->right, nodeQ->right});
            } else if (nodeP->right || nodeQ->right) {
                return false;
            }
        }

        return true;
    }
};