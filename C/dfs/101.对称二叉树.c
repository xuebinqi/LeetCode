/*
 * @lc app=leetcode.cn id=101 lang=c
 *
 * [101] 对称二叉树
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

bool dfs(struct TreeNode *root1, struct TreeNode *root2){
    if (!root1 && !root2) return true;
    if (!root1 || !root2) return false;
    if (root1->val != root2->val) return false;

    return dfs(root1->left, root2->right) && dfs(root1->right, root2->left);
}
bool isSymmetric(struct TreeNode* root){
    if (!root) return true;

    return dfs(root, root);
}


// 迭代
/*
bool isSymmetric(struct TreeNode* root){
    if (root == NULL) return true;

    struct TreeNode **que = (struct TreeNode **) malloc(sizeof(struct TreeNode *) * 1005);
    int leftIndex = 0, rightIndex = 0;
   
    que[rightIndex++] = root->left;
    que[rightIndex++] = root->right;

    while (leftIndex < rightIndex){
        struct TreeNode *leftNode = que[leftIndex++];
        struct TreeNode *rightNode = que[leftIndex++];

        if (!leftNode ^ !rightNode) return false;
        if (!leftNode && !rightNode) continue;
        if (leftNode->val != rightNode->val) return false;

        que[rightIndex++] = leftNode->left;
        que[rightIndex++] = rightNode->right;
        que[rightIndex++] = leftNode->right;
        que[rightIndex++] = rightNode->left;
    }

    return leftIndex == rightIndex;
}
*/

// @lc code=end

