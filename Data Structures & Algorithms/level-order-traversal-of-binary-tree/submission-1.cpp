class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) {
            return {};
        }

        vector<vector<int>> ans;
        queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);

        while (!nodeQueue.empty()) {
            int levelSize = nodeQueue.size();
            vector<int> tmp;

            for (int i = 0; i < levelSize; i++) {
                TreeNode* current = nodeQueue.front();
                nodeQueue.pop();

                tmp.push_back(current->val);

                if (current->left) {
                    nodeQueue.push(current->left);
                }

                if (current->right) {
                    nodeQueue.push(current->right);
                }
            }

            ans.push_back(tmp);
        }

        return ans;
    }
};