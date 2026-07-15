class Solution {
public:
    int count = 0;

    int pathSum(TreeNode* root, int target) {
        if (root == nullptr) {
            return 0;
        }
        dfs(root,(long long) target);

        pathSum(root->left, target);
        pathSum(root->right, target);

        return count;
    }
    void dfs(TreeNode* root, long long target) {
        if (root == nullptr) {
            return;
        }
        target -= root->val;
        if (target == 0) {
            count++;
        }
        dfs(root->left, target);
        dfs(root->right, target);
        return;
    }
};