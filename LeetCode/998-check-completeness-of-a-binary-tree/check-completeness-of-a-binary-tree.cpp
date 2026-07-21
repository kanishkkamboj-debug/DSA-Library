class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        // this question will be solved same as level order bus difference itna hai 
        // ki vector ki bjaye true false dena hai
        if (root == nullptr)
            return true;
        queue<TreeNode*> elements;
        elements.push(root);
        bool nullfound = false;
        // agar ek null ke baad element milta hai to direct false  return kardo
        while (!elements.empty()) {
            TreeNode* t = elements.front();
            elements.pop();
            if (t == nullptr) {
                nullfound = true;
            } else {
                if (nullfound) {
                    return false;
                }
                elements.push(t->left);
                elements.push(t->right);
            }
        }
        return true;
    }
};