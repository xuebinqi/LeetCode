/*
 * @lc app=leetcode.cn id=98 lang=c
 *
 * [98] 验证二叉搜索树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool dfs(struct TreeNode *root, long long lower, long long upper){
    if (!root) return true;

    if (root->val <= lower || root->val >= upper) {
        return false;
    }

    return dfs(root->left, lower, root->val) && dfs(root->right, root->val, upper);
}

bool isValidBST(struct TreeNode* root){
    if (!root) return true;

    return dfs(root, LONG_MIN, LONG_MAX);    
}
// @lc code=end

