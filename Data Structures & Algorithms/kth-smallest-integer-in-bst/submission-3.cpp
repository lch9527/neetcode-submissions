class Solution {
public:
    void dfs(TreeNode* root, int& k, int& answer) {
        if (!root || k == 0) {
            return;
        }

        dfs(root->left, k, answer);

        if (k == 0) {
            return;
        }

        k--;

        if (k == 0) {
            answer = root->val;
            return;
        }

        dfs(root->right, k, answer);
    }

    int kthSmallest(TreeNode* root, int k) {
        int answer = 0;
        dfs(root, k, answer);
        return answer;
    }
};