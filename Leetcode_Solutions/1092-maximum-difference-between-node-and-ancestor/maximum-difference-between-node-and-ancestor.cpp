
class Solution {
public:
    void helper(TreeNode* root, int maxi, int mini, int &diff)
    {
        if(!root) return;

        maxi = max(maxi, root->val);
        mini = min(mini, root->val);
        diff = max(diff, abs(maxi - mini));

        helper(root->left, maxi, mini, diff);
        helper(root->right, maxi, mini, diff);
    }
    int maxAncestorDiff(TreeNode* root) {
        if(!root) return 0;
        int diff = 0;
        helper(root, INT_MIN, INT_MAX, diff);
        return diff;
    }
};


