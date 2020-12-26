/*
 * @lc app=leetcode.cn id=257 lang=c
 *
 * [257] 二叉树的所有路径
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
 * Note: The returned array must be malloced, assume caller calls free().
 */

void constructPaths(struct TreeNode *root, char **paths, int *returnSize, int *sta, int top){
    if (root){
        if (root->left == NULL && root->right == NULL){
            char *node = (char *)malloc(1001);
            int len = 0;
            for (int i = 0; i < top; ++i){
                len += sprintf(node + len, "%d->", sta[i]);
            }
            
            sprintf(node + len, "%d", root->val);
            paths[(*returnSize)++] = node;
        } else{
            sta[top++] = root->val;
            constructPaths(root->left, paths, returnSize, sta, top);
            constructPaths(root->right, paths, returnSize, sta, top);
        }
    }
}

char ** binaryTreePaths(struct TreeNode* root, int* returnSize){
    char **paths = (char **)malloc(sizeof(char *) * 1001);
    *returnSize = 0;
     if (root == NULL) return paths;
    int sta[1001];
    constructPaths(root, paths, returnSize, sta, 0);

    return paths;
}   


// @lc code=end

