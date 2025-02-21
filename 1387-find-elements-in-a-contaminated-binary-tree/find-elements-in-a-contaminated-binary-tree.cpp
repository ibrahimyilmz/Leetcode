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
class FindElements {
private:
    TreeNode* root;
    void FindElementsHelper(TreeNode* root, int val) {
        if (!root) {
            return;
        }

        root->val = val;

        FindElementsHelper(root->left, val * 2 + 1);
        FindElementsHelper(root->right, val * 2 + 2);
    }
    bool findHelper(TreeNode* root, int target) {
        if (!root) return false;

        if (root->val == target) return true;

        bool l = findHelper(root->left, target);
        bool r = findHelper(root->right, target);

        return l | r;
    }
public:
    FindElements(TreeNode* root) {
        this->root = root;
        root->val = 0;
        FindElementsHelper(root, 0);
    }
    
    bool find(int target) {
        return findHelper(root, target);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */