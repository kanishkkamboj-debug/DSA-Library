class Solution {
public:
    void adder(TreeNode* root, vector<string>& res, string word) {
        if (root == nullptr)
            return;
        word += to_string(root->val);
        if (root->right == nullptr && root->left == nullptr) {
            res.push_back(word);
            return;
        }
        adder(root->right, res, word);
        adder(root->left, res, word);
        return;
    }
    int res(vector<string>& res) {
        int ans = 0;
        for (auto& val : res) {
            ans += stoi(val);
        }
        return ans;
    }
    int sumNumbers(TreeNode* root) {
        vector<string> sum;
        adder(root, sum, "");
        return res(sum);
    }
};