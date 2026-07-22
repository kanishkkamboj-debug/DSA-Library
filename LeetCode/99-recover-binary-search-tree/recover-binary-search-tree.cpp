class Solution {
public:
    TreeNode* prev = nullptr;
    TreeNode* first = nullptr;
    TreeNode* second = nullptr;

    void arr(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        arr(root->left);
        if (prev != nullptr && root->val < prev->val) {
            if (first == nullptr) {
                first = prev;
            }
            second = root;
        }
        prev = root;
        arr(root->right);
    }
    void recoverTree(TreeNode* root) {
        arr(root);
        int temp = first->val;
        first->val = second->val;
        second->val = temp;
    }
};