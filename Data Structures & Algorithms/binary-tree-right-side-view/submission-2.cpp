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
    vector<int> rightSideView(TreeNode* root) {
        if(!root){
            return {};
        }
        vector<int> ans;
        queue<TreeNode*> que;
        que.push(root);

        while(!que.empty()){

            int qsize = que.size();

            for(int i = 0; i< qsize; i++){
                TreeNode* tmp = que.front();
                if(i == qsize - 1){
                    ans.push_back(tmp->val);
                }
                que.pop();

                if(tmp->left){
                    que.push(tmp->left);
                }
                if(tmp->right){
                    que.push(tmp->right);
                }
            }
        }

        return ans;
    }
};
