/*
 * @lc app=leetcode.cn id=129 lang=c
 *
 * [129] 求根到叶子节点数字之和
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
int totalSum;

void dfs(struct TreeNode* root, int pathSum){
    if (!root) return ;
    pathSum = pathSum * 10 + root->val;
    if (root->left == NULL && root->right == NULL){
        totalSum += pathSum;
        return;
    }

    dfs(root->left, pathSum);
    dfs(root->right, pathSum);
}

int sumNumbers(struct TreeNode* root){
    if (!root) return 0;
    totalSum = 0;
    int pathSum = 0;
    dfs(root, pathSum);

    return totalSum;
}


// @lc code=end

