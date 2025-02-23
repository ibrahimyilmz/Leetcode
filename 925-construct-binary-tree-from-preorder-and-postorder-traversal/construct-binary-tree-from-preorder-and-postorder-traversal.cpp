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
    TreeNode* helper(vector<int>& preorder, vector<int>& postorder,
                         int preStart, int preEnd, int post) {
        if (preStart > preEnd) {
            return nullptr;
        }

        if (preStart == preEnd) {
            return new TreeNode(preorder[preStart]);
        }

        int leftNum = preorder[preStart + 1];
        int leftSize = 1;

        while (postorder[post + leftSize - 1] != leftNum) {
            leftSize++;
        }
        
        TreeNode* root = new TreeNode(preorder[preStart]);
        root->left = helper(preorder, postorder, preStart  + 1,
                                preStart + leftSize, post);
        root->right = helper(preorder, postorder, preStart + leftSize + 1,
                                preEnd, post + leftSize);

        return root;
    }
public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        return helper(preorder, postorder, 0, preorder.size() - 1, 0);
    }
};