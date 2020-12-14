/*
 * @lc app=leetcode.cn id=111 lang=c
 *
 * [111] 二叉树的最小深度
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

int minDepth(struct TreeNode* root){
    if (!root) return 0;
    if (!root->left && !root->right) return 1;
    int depth = INT_MAX;
    if (root->left){
        depth = fmin(depth, minDepth(root->left));
    }
    if (root->right){
        depth = fmin(depth, minDepth(root->right));
    }
        
    return depth + 1;
}
// @lc code=end

