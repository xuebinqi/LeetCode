/*
 * @lc app=leetcode.cn id=105 lang=c
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
int *tmpPreorder;
int *tmpInOrder;
struct TreeNode *dfs(int preLeft, int preRight, int inLeft, int inRight) {
    if (preLeft > preRight) return NULL;
   
    struct TreeNode *root = (struct TreeNode *) malloc(sizeof(struct TreeNode));
    int value = tmpPreorder[preLeft];
    root->val = value;
    int index = -1;
    for (int i = inLeft; i <= inRight; ++i){
        if (tmpInOrder[i] == value){
            index = i;
            break;
        }
    }
    root->left = dfs(preLeft + 1, preLeft + index - inLeft, inLeft, index - 1);
    root->right = dfs(preLeft + index - inLeft + 1, preRight, index + 1, inRight);

    return root;
}

struct TreeNode *buildTree(int *preorder, int preorderSize, int *inorder, int inorderSize) {
    if (preorderSize == 0 || inorderSize == 0 || preorderSize != inorderSize) return NULL;
    tmpPreorder = preorder;
    tmpInOrder = inorder;

    return dfs(0, preorderSize - 1, 0, inorderSize - 1);
}

// @lc code=end

