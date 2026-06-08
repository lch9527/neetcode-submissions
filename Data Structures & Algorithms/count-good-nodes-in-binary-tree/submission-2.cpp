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
    int ans = 0;
    void dfs(TreeNode* root, int pre){
        if(!root){
            return ;
        }
        if(root->val >= pre){
            ans++;
        }
        pre = max(pre,root->val);
        dfs(root->left,pre);
        dfs(root->right,pre);

    }
    int goodNodes(TreeNode* root) {
        dfs(root,root->val);
        return ans;
    }
};
