/*
 * @lc app=leetcode.cn id=124 lang=c
 *
 * [124] 二叉树中的最大路径和
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

int maxSum;

int dfs(struct TreeNode *root){
    if (!root) return 0;

    int leftGain = fmax(dfs(root->left), 0);
    int rightGain = fmax(dfs(root->right), 0);
    int priceNewPath = leftGain + rightGain + root->val;
    maxSum = fmax(maxSum, priceNewPath);
    return root->val + fmax(leftGain, rightGain); 
}


int maxPathSum(struct TreeNode* root){
    maxSum = INT_MIN;
    dfs(root);

    return maxSum;
}
// @lc code=end

