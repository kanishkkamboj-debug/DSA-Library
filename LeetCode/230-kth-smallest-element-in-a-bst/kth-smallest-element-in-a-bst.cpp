class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> st;
        TreeNode* current = root;
        int count = 0;
        while (current != nullptr || !st.empty()) {
            while (current != nullptr) {
                st.push(current);
                current = current->left;
            }
            current = st.top();
            st.pop();

            count++;
            if (count == k) {
                return current->val;
            }
            current = current->right;
        }
        return -1;
    }
};