/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        queue<TreeNode*> q;
        q.push(root);
        bool dir = 0;
        
        while(!q.empty())
        {
            int size = q.size();
            vector<int> level;
            for(int i = 0; i < size; i++)
            {
                TreeNode* node = q.front();
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);

                level.push_back(node->val);
            }
            //if dir is 1 -> opp then reverse and then push
            if(dir)
            {
                reverse(level.begin(), level.end());
                ans.push_back(level);
                dir = 0;
            }
            //if dir is 0 then push directly
            else
            {
                ans.push_back(level);
                dir = 1;
            }
            
        }
        return ans;
    }
};