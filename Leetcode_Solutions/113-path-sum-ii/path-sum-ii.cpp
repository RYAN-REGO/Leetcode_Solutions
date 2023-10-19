
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;

    void helper(TreeNode* root, int target, vector<int>& path, vector<vector<int>>& ans)
    {
        if(!root) return;
        path.push_back(root->val);

        if(!root->left && !root->right && target == root->val)
        {
            ans.push_back(path);
        }
        helper(root->left, target - root->val, path, ans);
        helper(root->right, target - root->val, path, ans);

        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(!root) return ans;
        helper(root, targetSum, path, ans);
        return ans;
    }
};