/*
 * @lc app=leetcode.cn id=113 lang=c
 *
 * [113] 路径总和 II
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


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int **res;
int resSize;
int *resColSize;

int *path;
int pathSize;

void dfs(struct TreeNode *root, int sum){
    if (!root) return;
    path[pathSize++] = root->val;
    sum = sum - root->val;
    
    if (root->left == 0 && root->right == 0 && sum == 0){
        int *tmp = malloc(sizeof(int) * pathSize);
        memcpy(tmp, path, sizeof(int) * pathSize);
        res[resSize] = tmp;
        resColSize[resSize++] = pathSize;
    }

    dfs(root->left, sum);
    dfs(root->right, sum);
    --pathSize;

}

int** pathSum(struct TreeNode* root, int sum, int* returnSize, int** returnColumnSizes){
    res = malloc(sizeof(int *) * 2005);
    resColSize = malloc(sizeof(int) * 2005);
    path = malloc(sizeof(int) * 2005);
    memset(path, 0, sizeof(path));
    resSize = pathSize = 0;
    dfs(root, sum);
    *returnSize = resSize;
    *returnColumnSizes = resColSize;

    return res;
}


// @lc code=end

