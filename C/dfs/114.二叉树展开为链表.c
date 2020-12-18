/*
 * @lc app=leetcode.cn id=114 lang=c
 *
 * [114] 二叉树展开为链表
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

void flatten(struct TreeNode* root){
    if (!root) return ;
    struct TreeNode *curr = root;
    
    while (curr) {
        if (curr->left){
            struct TreeNode *next = curr->left;
            struct TreeNode *predecessor = next;
            while (predecessor->right){
                predecessor = predecessor->right;
            }

            predecessor->right = curr->right;
            curr->left = NULL;
            curr->right = next;

        }

        curr = curr->right;
    }
}

// @lc code=end

