/*
 * @lc app=leetcode.cn id=110 lang=c
 *
 * [110] 平衡二叉树
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

// 自顶向下 时间复杂度O(n^2)
// #define max(a, b) ((a) > (b) ? (a) : (b))

// int height(struct TreeNode* root){
//     if (!root) return 0;
//     int left = height(root->left) + 1;
//     int right = height(root->right) + 1;

//     return max(left, right);
// }

// bool isBalanced(struct TreeNode* root){
//     if (!root) return true;
//     int left = height(root->left);
//     int right = height(root->right);
//     if (left - right > 1 || right - left > 1) return false;

//     return isBalanced(root->left) && isBalanced(root->right);
// }

/*自底向上时间复杂度O(n), 时间复杂度O(n)*/

int height(struct TreeNode *root){
    if (!root) return 0;
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    if (leftHeight == -1 || rightHeight == -1 || fabs(leftHeight - rightHeight) > 1){
        return -1;
    }
    else{
        return fmax(leftHeight, rightHeight) + 1;
    }
}

bool isBalanced(struct TreeNode* root) {
    return height(root) >= 0;
}

// @lc code=end

