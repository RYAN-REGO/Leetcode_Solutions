
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return nullptr;

        TreeNode* node = root->right;
        root->right = root->left;
        root->left = node;

        if(root->left) invertTree(root->left);
        if(root->right) invertTree(root->right);

        return root;
    }
};