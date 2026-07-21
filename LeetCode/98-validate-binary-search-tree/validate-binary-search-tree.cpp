class Solution {
public:
    bool ans(TreeNode* root, long long low, long long high) {
        // check if root is null
        if (root == nullptr) {
            return true;
        }
        // jo abhi wali node hai woh low and high ki range mein liye karti hai
        // ki nahi??
        if (root->val <= low || root->val >= high) {
            return false;
        }
        // left subtree  ki valus <root-> val right sub tree ki val >root-> val
        // ki nahi??
        return ans(root->left, low, root->val) &&
               ans(root->right, root->val, high);
    }
    bool isValidBST(TreeNode* root) { return ans(root, LLONG_MIN, LLONG_MAX); }
};