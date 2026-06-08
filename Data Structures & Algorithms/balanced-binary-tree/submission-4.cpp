class Solution {
public:
    vector<int> dfs(TreeNode* root) {
        if (!root) {
            return {1, 0};
        }

        vector<int> left = dfs(root->left);
        vector<int> right = dfs(root->right);

        bool isbalanced = left[0] && right[0] &&
                          abs(left[1] - right[1]) <= 1;

        int height = 1 + max(left[1], right[1]);

        return {isbalanced, height};
    }

    bool isBalanced(TreeNode* root) {
        return dfs(root)[0];
    }
};