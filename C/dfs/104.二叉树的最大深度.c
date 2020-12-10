/*
 * @lc app=leetcode.cn id=104 lang=c
 *
 * [104] 二叉树的最大深度
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
// 递归
int maxDepth(struct TreeNode *root){
    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);

    return leftDepth > rightDepth ? leftDepth + 1: rightDepth + 1;
}

// 迭代
/*
int maxDepth(struct TreeNode* root){
    if (!root) return 0;
    struct TreeNode *queue[10005];
    int head = 0, tail = 0;
    struct TreeNode *node = root;
    int depth = 0;
    int level = 0;
    queue[tail++] = node;
    while (head < tail){
        ++depth;
        level = tail;
        for (int i = head; i < level; ++i){
            node = queue[i];
            if (node->left){
                queue[tail++] = node->left;
            }
            if (node->right){
                queue[tail++] = node->right;
            }
        }
        head = level;
    }

    return depth;
}
*/

// @lc code=end

