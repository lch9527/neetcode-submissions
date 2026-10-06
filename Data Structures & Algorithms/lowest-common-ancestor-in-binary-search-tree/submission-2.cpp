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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans = dfs(root, p, q);

        return ans;
    }

    TreeNode* dfs(TreeNode* root, TreeNode* p, TreeNode* q){
        if(!root){
            return nullptr;
        }

        if(root == p){
            return p;
        }
        else if (root == q){
            return q;
        }

        if(root->val > max(p->val,q->val)){
           return dfs(root->left,p,q);
        }
        else if (root->val < min(p->val,q->val)){
           return dfs(root->right,p,q);
        }

        return root;

    }
};
