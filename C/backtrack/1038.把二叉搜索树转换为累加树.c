/*
 * @lc app=leetcode.cn id=1038 lang=c
 *
 * [1038] 把二叉搜索树转换为累加树
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
int sum;

struct TreeNode *dfs(struct TreeNode *root){
    if (root){
        dfs(root->right);
        sum += root->val;
        root->val = sum;
        dfs(root->left);
    }

    return root;
}

struct TreeNode* bstToGst(struct TreeNode* root){
    sum = 0;
    dfs(root);

    return root;
}
// @lc code=end

