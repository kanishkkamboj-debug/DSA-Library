class Solution {
public:
    unordered_map<int, int> in;
    int idx = 0;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        in.clear();
        for (int i = 0; i < inorder.size(); i++) {
            in[inorder[i]] = i;
        }
        return create(preorder, 0, preorder.size()-1);
    }
    TreeNode* create(vector<int>& preorder, int low, int high) {
        if (low > high) {
            return nullptr;
        }
        TreeNode* node = new TreeNode(preorder[idx]);
        idx++;
        int id = in[node->val];
        node->left = create(preorder, low, id - 1);
        node->right = create(preorder, id + 1, high);
        return node;
    }
};