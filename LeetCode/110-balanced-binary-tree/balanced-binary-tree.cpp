class Solution {
public:
    bool isBalanced(TreeNode* root) { 
        return ans(root) != -1; 
        }
    int ans(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int left = ans(root->left);
        int right = ans(root->right);

        if (left == -1 || right == -1) {
            return -1;
        }
        if (abs(left - right) > 1) {
            return -1;
        }
        return 1 + max(left, right);
    }
};