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
private:
    int perorderIndex = 0;
    unordered_map<int,int> inorderMap;
public:

    TreeNode* build(vector<int>& preorder, int left, int right){
        if(left>right){
            return nullptr;
        }
        int val = preorder[perorderIndex];
        perorderIndex++;
        int mIndex = inorderMap[val];

        TreeNode* root = new TreeNode(val);

        root->left = build(preorder, left, mIndex-1);
        root->right = build(preorder, mIndex+1, right);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int inorderleft = 0;
        int inorderRight = inorder.size()-1;
        for(int i = 0; i< inorder.size(); i++){
            inorderMap[inorder[i]] = i;
        }

        return build(preorder, inorderleft, inorderRight);

    }
};
