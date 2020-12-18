/*
 * @lc app=leetcode.cn id=117 lang=c
 *
 * [117] 填充每个节点的下一个右侧节点指针 II
 */

// @lc code=start
/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *left;
 *     struct Node *right;
 *     struct Node *next;
 * };
 */

void handle (struct Node **last, struct Node **p, struct Node **nextStart){
    if (*last){
        (*last)->next = *p;
    }

    if (!(*nextStart)){
        *nextStart = *p;
    }

    *last = *p;
}

struct Node* connect(struct Node* root) {
	if (!root) return root;
    struct Node * start = root;
    while (start){
        struct Node *last = NULL, *nextStart = NULL;
        for (struct Node *p = start; p != NULL; p = p->next){
            if (p->left){
                handle(&last, &(p->left), &nextStart);
            }

            if (p->right){
                handle(&last, &(p->right), &nextStart);
            }
        }

        start = nextStart;
    }

    return root;
}
// @lc code=end

