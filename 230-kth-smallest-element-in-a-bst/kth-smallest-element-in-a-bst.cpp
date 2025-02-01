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
    void dfs(TreeNode* root, vector<int> &vec) {
        if (!root) return;

        dfs(root->left, vec);
        vec[0]--;
        if (vec[0] == 0) {
            vec[1] = root->val;
            return;
        }
        dfs(root->right, vec);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> vec(2);
        vec[0] = k;

        dfs(root, vec);
        return vec[1];
    }
};