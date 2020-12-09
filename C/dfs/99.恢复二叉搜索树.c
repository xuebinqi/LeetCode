/*
 * @lc app=leetcode.cn id=99 lang=c
 *
 * [99] 恢复二叉搜索树
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


void recoverTree(struct TreeNode* root){
    struct TreeNode *x = NULL, *y = NULL, *pred = NULL, *predecessor = NULL;
    while (root){
        if (root->left){
            // predecessor 节点就是当前 root 节点向左走一步，然后一直向右走至无法走为止
            predecessor = root->left;
            while (predecessor->right && predecessor->right != root){
                predecessor = predecessor->right;
            }

            // 让 predecessor 的右指针指向 root，继续遍历左子树
            if (predecessor->right == NULL){
                predecessor->right = root;
                root = root->left;
            } else { // 说明左子树已经访问完了，我们需要断开链接
                if (pred && root->val < pred->val){
                    y = root;
                    if (x == NULL){
                        x = pred;
                    }
                }

                pred = root;
                predecessor->right = NULL;
                root = root->right;
            }
        } else{ // 如果没有左孩子，则直接访问右孩子
            if (pred && root->val < pred->val){
                y = root;
                if (x == NULL){
                    x = pred;
                }
            }

            pred = root;
            root = root->right;
        }
    }

    int t = x->val;
    x->val = y->val;
    y->val = t;
}
// @lc code=end

