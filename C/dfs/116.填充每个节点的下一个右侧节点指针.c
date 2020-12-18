/*
 * @lc app=leetcode.cn id=116 lang=c
 *
 * [116] 填充每个节点的下一个右侧节点指针
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

struct Node* connect(struct Node* root) {
	if (!root) return root;

    struct Node *curr = root;
    while (curr->left != NULL){
        struct Node *head = curr;
        while (head) {
            head->left->next = head->right;
            if (head->next){
                head->right->next = head->next->left;
            }

            head = head->next;
        }
        curr = curr->left;
    }

    return root;
}
// @lc code=end

