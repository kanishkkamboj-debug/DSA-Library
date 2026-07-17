class Solution {
public:
    int diameter = 0;
    int count(TreeNode* root) {

        if (root == nullptr)
            return 0;

        int left = count(root->right);
        int right = count(root->left);

        diameter = max(diameter, left + right);

        return 1 + max(left, right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        count(root);
        return diameter;
    }
};