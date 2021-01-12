/*
 * @lc app=leetcode.cn id=103 lang=c
 *
 * [103] 二叉树的锯齿形层次遍历
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
#define MAXN 2000

int** zigzagLevelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    *returnSize = 0;
    if (root == NULL) {
        return NULL;
    }
    int** ans = malloc(sizeof(int*) * MAXN);
    *returnColumnSizes = malloc(sizeof(int) * MAXN);
    struct TreeNode* nodeQueue[MAXN];
    int left = 0, right = 0;
    nodeQueue[right++] = root;
    bool isOrderLeft = true;
    while (left < right) {
        int levelList[MAXN * 2];
        int front = MAXN, rear = MAXN;
        int size = right - left;
        for (int i = 0; i < size; ++i) {
            struct TreeNode *node = nodeQueue[left++];
            if (isOrderLeft) {
            levelList[rear++] = node->val;
            } else {
                levelList[--front] = node->val;
            }

            if (node->left) {
                nodeQueue[right++] = node->left;
            }

            if (node->right) {
                nodeQueue[right++] = node->right;
            }
        }
        
        int *tmp = malloc(sizeof(int) * (rear-front));
        for (int i = 0; i < rear - front; ++i) {
            tmp[i] = levelList[i + front];
        }

        ans[*returnSize] = tmp;
        (*returnColumnSizes)[*returnSize] = rear - front;
        (*returnSize)++;
        isOrderLeft = !isOrderLeft;
    }

    return ans;
}


// @lc code=end

