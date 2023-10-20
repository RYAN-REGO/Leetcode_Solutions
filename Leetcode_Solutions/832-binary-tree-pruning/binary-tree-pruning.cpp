
class Solution {
public:
    int helper(TreeNode* root)
    {
        if(!root) return 0;

        //for leaf node
        if(!root->left && !root->right)
        {
            if(root->val == 0) return 0;
            else return 1; 
        } 
        int leftSTree = helper(root->left);
        int rightSTree = helper(root->right);

        if(leftSTree == 0) root->left = nullptr;
        if(rightSTree == 0) root->right = nullptr;

        return leftSTree + rightSTree + (root->val == 1 ? 1 : 0);
    }
    TreeNode* pruneTree(TreeNode* root) {
        if(!root) return nullptr;

        int ans = helper(root);
        if(ans == 0) return NULL;
        return root;
    }
};