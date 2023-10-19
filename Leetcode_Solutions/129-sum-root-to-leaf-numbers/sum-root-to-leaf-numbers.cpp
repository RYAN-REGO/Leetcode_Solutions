
class Solution {
public:
    int helper(TreeNode* root, int sum)
    {
        if(!root) return 0;
        sum = sum * 10 + root->val;

        if(!root->left && !root->right) return sum;

        int lh = helper(root->left, sum);
        int rh = helper(root->right, sum);

        return lh + rh;
    }
    int sumNumbers(TreeNode* root) {
        int ans = helper(root, 0);
        return ans;
    }
};