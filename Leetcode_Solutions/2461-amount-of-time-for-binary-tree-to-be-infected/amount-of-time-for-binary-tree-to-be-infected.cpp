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
    void markParent(TreeNode* root,unordered_map<TreeNode*,TreeNode*>& parent) {
        queue<TreeNode*> q;

        q.push(root);

        while(!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();

            if(curr->left) {
                q.push(curr->left);
                parent[curr->left] = curr; 
            }

            if(curr->right) {
                q.push(curr->right);
                parent[curr->right] = curr;
            }
        }
    }

    TreeNode* findTarget(TreeNode* root, int start) {
        if (root == nullptr)
            return nullptr;

        if (root->val == start)
            return root;

        TreeNode* leftResult = findTarget(root->left, start);
        if (leftResult != nullptr)
            return leftResult;

        return findTarget(root->right, start);
}


    int amountOfTime(TreeNode* root, int start) {
        if(root->left == NULL && root->right == NULL && root->val == start)
            return 0;

        unordered_map<TreeNode*,TreeNode*> parent;

        markParent(root,parent);

        TreeNode* target = findTarget(root,start);

        if(target == NULL)
            return 0;

        unordered_map<TreeNode*,bool> visited;

        queue<TreeNode*> q;

        q.push(target);
        visited[target] = true;
        int minutes = 0;


        while(!q.empty()) {
            int size = q.size();

            for(int i=0;i<size;i++) {
                TreeNode* curr = q.front();
                q.pop();

                

                if(curr->left && !visited[curr->left]) {
                    q.push(curr->left);
                    visited[curr->left] = true;
                }

                if(curr->right && !visited[curr->right]) {
                    q.push(curr->right);
                    visited[curr->right] = true;
                }

                if(parent[curr] && !visited[parent[curr]]) {
                    q.push(parent[curr]);
                    visited[parent[curr]] = true;
                }
            }

            minutes++;
        }


        return minutes-1;
    }
};