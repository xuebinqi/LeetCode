/*
 * @lc app=leetcode.cn id=106 lang=c
 *
 * [106] 从中序与后序遍历序列构造二叉树
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
int *tmpInorder;
int *tmpPostorder;

struct TreeNode *dfs(int inLeft, int inRight, int postLeft, int postRight){
    if (postLeft > postRight) return NULL;
    struct TreeNode *root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    int value = tmpPostorder[postRight];
    root->val = value;

    int index = -1;
    for (int i = inLeft; i <= inRight; ++i){
        if (tmpInorder[i] == value){
            index = i;
            break;
        }
    }

    root->left = dfs(inLeft, index - 1, postLeft, postLeft + index - inLeft - 1);
    root->right = dfs(index + 1, inRight, postLeft + index - inLeft, postRight - 1);

    return root;
}

struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize){
    if (inorderSize == 0 || postorderSize == 0 || inorderSize != postorderSize) return NULL;
    tmpInorder = inorder;
    tmpPostorder = postorder;
    return dfs(0, inorderSize - 1, 0, postorderSize - 1);
}


// @lc code=end

