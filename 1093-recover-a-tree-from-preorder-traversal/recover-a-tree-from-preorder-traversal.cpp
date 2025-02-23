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
    TreeNode* helper(const string& traversal, int level, int& curr) {
        if (curr >= traversal.size()) {
            return nullptr;
        }

        int dashes = 0;
        while (curr + dashes < traversal.size() &&
                    traversal[curr + dashes] == '-') {
            dashes++;
            
        }

        if (dashes != level) {
            return nullptr;
        }

        curr += level;

        int val = 0;
        while (curr < traversal.size() && isdigit(traversal[curr])) {
            val = val * 10 + (traversal[curr] - '0');
            curr++;
        }

        TreeNode* root = new TreeNode(val);

        root->left = helper(traversal, level + 1, curr);
        root->right = helper(traversal, level + 1, curr);

        return root;
    }
public:
    TreeNode* recoverFromPreorder(string traversal) {
        int curr = 0;
        return helper(traversal, 0, curr);
    }
};