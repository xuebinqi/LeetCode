/*
 * @lc app=leetcode.cn id=107 lang=c
 *
 * [107] 二叉树的层次遍历 II
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
int** levelOrderBottom(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    int **result =  (int **) malloc(sizeof(int *) * 2001);
    *returnColumnSizes = (int *)malloc(sizeof(int) * 2001);

    *returnSize = 0;
    if (root == NULL) {
        return result;
    }
    // struct TreeNode *queue[2001];
    struct TreeNode **queue =(struct TreeNode *)malloc(sizeof(struct TreeNode*) * 2001);

    int start = 0, end = 0;
    queue[end++] = root;
    while (start < end){
        int len = end - start;
        int * level = (int *)malloc(sizeof(int) * len);
        (*returnColumnSizes)[*returnSize] = len;
        for (int i = 0; i < len; ++i){
            struct TreeNode *node = queue[start++];
            level[i] = node->val;
            if (node->left){
                queue[end++] = node->left;
            }
            if (node->right){
                queue[end++] = node->right;
            }
        }

        result[(*returnSize)++] = level;
    }

    for (int i = 0; 2 * i < *returnSize; ++i){
        int *tmp1 = result[i];
        result[i] = result[(*returnSize)-i-1];
        result[(*returnSize)-i-1] = tmp1;

        int tmp2 = (*returnColumnSizes)[i];
        (*returnColumnSizes)[i] =  (*returnColumnSizes)[(*returnSize)-i-1];
        (*returnColumnSizes)[(*returnSize)-i-1] = tmp2;
    }

    return result;
}



// @lc code=end

