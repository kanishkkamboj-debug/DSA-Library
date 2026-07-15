class Solution {
public:
    vector<vector<int>> res;
    vector<int> item;
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        dfs(root, target);
        return res;
    }
    void dfs(TreeNode* root, int target) {
        if (root == nullptr) {
            return;
        }
        target -= root->val;
        item.push_back(root->val);
        if (root->left == nullptr && root->right == nullptr) {
            if (target == 0) {
                res.push_back(item);
            }
        }
        dfs(root->left, target);
        dfs(root->right, target);
        item.pop_back();
        return;
    }
};