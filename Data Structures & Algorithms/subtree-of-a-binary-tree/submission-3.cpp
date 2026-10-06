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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root){
            return false;
        }


        if(root->val == subRoot->val){
            if (isSame(root, subRoot)) {
                return true;
            }
        }

        return (isSubtree(root->right,subRoot) || isSubtree(root->left,subRoot)); 
    }

    bool isSame(TreeNode* q, TreeNode* p){
        if(!q && !p){
            return true;
        }

        if(!q || !p){
            return false; 
        }

        if(p->val != q->val){
            return false;
        }

        return (isSame(q->left,p->left) &&
                isSame(q->right,p->right));
    }
};
