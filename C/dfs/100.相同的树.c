/*
 * @lc app=leetcode.cn id=100 lang=c
 *
 * [100] 相同的树
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
bool isSameTree(struct TreeNode* p, struct TreeNode* q){
    if (!p && !q) return true;
    if (!p || !q) return false;
    if (p->val != q->val) return false;
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}
/*
// 队列
bool isSameTree(struct TreeNode* p, struct TreeNode* q){
    if (!p && !q) return true;
    if (!p || !q) return false;

    struct TreeNode **que1 = (struct TreeNode **) malloc(sizeof(struct TreeNode *));
    struct TreeNode **que2 = (struct TreeNode **) malloc(sizeof(struct TreeNode *));

    int queleft1 = 0;
    int queright1 = 0;
    int queleft2 = 0;
    int queright2 = 0;

    que1[queright1++] = p;
    que2[queright2++] = q;
    while (queleft1 < queright1 && queleft2 < queright2){
        struct TreeNode *node1 = que1[queleft1++];
        struct TreeNode *node2 = que2[queleft2++];
        if (node1->val != node2->val){
            return false;
        }

        struct TreeNode *left1 = node1->left;
        struct TreeNode *right1 = node1->right;
        struct TreeNode *left2 = node2->left;
        struct TreeNode *right2 = node2->right;

        if ((!left1) ^ (!left2)) return false;
        if ((!right1) ^ (!right2)) return false;

        if (left1){
            ++queright1;
            que1 = realloc(que1, sizeof(struct TreeNode *) * queright1);
            que1[queright1 - 1] = left1;
        }

        if (right1){
            ++queright1;
            que1 = realloc(que1, sizeof(struct TreeNode *) * queright1);
            que1[queright1 - 1] = right1;
        }

        if (left2){
            ++queright2;
            que2 = realloc(que2, sizeof(struct TreeNode *) * queright2);
            que2[queright2 - 1] = left2;
        }

        if (right2){
            ++queright2;
            que2 = realloc(que2, sizeof(struct TreeNode *) * queright2);
            que2[queright2 - 1] = right2;
        }
    }

    return queleft1 == queright1 && queleft2 == queright2;
}

*/
// @lc code=end

