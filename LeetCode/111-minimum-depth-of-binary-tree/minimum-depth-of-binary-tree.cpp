class Solution {
public:
    // if liked the code please upvote 
    int minDepth(TreeNode* root) { 
        return ans(root); 
        }
    int ans(TreeNode* root) {
        //base case
        if (root == nullptr) {
            return 0;
        }
        //dono child dekh rahe hai ki root no child hai!!
        if (root->left == nullptr && root->right == nullptr) {
            return 1;
        }
        //agar root ki left side khali hai toh right side jao!!
        if (root->left == nullptr) {
            return 1 + ans(root->right);
        }
        //agar root li right side khali hai toh left side jao ulta 
        if (root->right == nullptr) {
            return 1 + ans(root->left);
        }
        //warna dono mein se min
        return 1 + min(ans(root->left), ans(root->right));
    }
};