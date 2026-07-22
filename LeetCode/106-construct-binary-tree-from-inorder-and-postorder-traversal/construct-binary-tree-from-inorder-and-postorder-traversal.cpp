class Solution {
public:
    unordered_map<int, int> in;
    int idx = 0;

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        in.clear();
        for (int i = 0; i < inorder.size(); i++) {
            in[inorder[i]] = i;
        }
        idx = postorder.size() - 1;
        return create(postorder, 0, postorder.size() - 1);
    }
    
    TreeNode* create(vector<int>& postorder, int low, int high) {
        if (low > high) {
            return nullptr;
        }
        TreeNode* node = new TreeNode(postorder[idx]);
        idx--;
        int id = in[node->val];
        node->right = create(postorder, id + 1, high);
        node->left = create(postorder, low, id - 1);

        return node;
    }
};