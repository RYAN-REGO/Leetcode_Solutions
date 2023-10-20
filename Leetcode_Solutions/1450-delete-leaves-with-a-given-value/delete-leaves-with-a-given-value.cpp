
class Solution {
public:
    int helper(TreeNode* root, int target)
    {
        if(!root) return 0;

        if(!root->left && !root->right)
        {
            if(root->val == target) return 0;
            else return 1;
        }

        int leftSubTree = helper(root->left, target);
        int rightSubTree = helper(root->right, target);

        if(leftSubTree == 0)
        {
            root->left = NULL;
        }
        if(rightSubTree == 0)
        {
            root->right = NULL;
        }
        //very important to NOTE..
        return leftSubTree + rightSubTree + (root->val == target ? 0 : 1);
    }
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if(!root) return nullptr;

        int ans = helper(root, target);
        if(ans == 0) return NULL;
        return root;
    }
};