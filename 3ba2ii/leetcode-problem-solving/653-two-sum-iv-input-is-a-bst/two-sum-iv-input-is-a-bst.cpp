
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> mp;
        return dfs(root, k, mp);
    }
    bool dfs(TreeNode* root, int k, unordered_set<int>& mp) {
        if (!root)
            return false;
        if (mp.count(k - root->val))
            return true;
        mp.insert(root->val);
        return dfs(root->left, k, mp) || dfs(root->right, k, mp);
    }
};