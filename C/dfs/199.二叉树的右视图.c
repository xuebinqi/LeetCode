/*
 * @lc app=leetcode.cn id=199 lang=c
 *
 * [199] 二叉树的右视图
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


#define MAXSIZE 1005
void dfs(struct TreeNode *root, int depth, int *res, int *returnSize){
    if (!root) return ;

    if (depth == *(returnSize)){
        res[(*returnSize)++] = root->val;
    }

    dfs(root->right, depth + 1, res, returnSize);
    dfs(root->left, depth + 1, res, returnSize);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* rightSideView(struct TreeNode* root, int* returnSize){
    if (!root) {
        *returnSize = 0;
        return NULL;
    }

    int *res = malloc(sizeof(int) * MAXSIZE);
    *returnSize = 0;
    dfs(root, 0, res, returnSize);

    return res;
}


// @lc code=end

