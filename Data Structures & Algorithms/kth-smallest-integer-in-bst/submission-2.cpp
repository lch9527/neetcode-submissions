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
    void dfs(TreeNode* root, vector<int>& ans, int k){
        if(!root){
            return;
        }
        if(ans.size()>k){
            return;
        }
        dfs(root->left, ans,k);
        ans.push_back(root->val);
        dfs(root->right, ans,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> ans;
        dfs(root,ans,k);
        return ans[k-1];
    }
};
