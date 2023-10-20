
class Solution {
public:
    int cnt = 0;
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        cnt += 1;
        if(root->left) countNodes(root->left);
        if(root->right) countNodes(root->right);

        return cnt;
    }
};