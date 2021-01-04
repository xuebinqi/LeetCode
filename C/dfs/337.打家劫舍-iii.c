/*
 * @lc app=leetcode.cn id=337 lang=c
 *
 * [337] 打家劫舍 III
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

struct SubTreeStatus{
    int selceted;
    int notSelected;
};

struct SubTreeStatus dfs(struct TreeNode *root){
    if (!root) return (struct SubTreeStatus) {0, 0};

    struct SubTreeStatus left = dfs(root->left);
    struct SubTreeStatus right = dfs(root->right);
    int selected = root->val + left.notSelected + right.notSelected;
    int notSelected = fmax(left.selceted, left.notSelected) + fmax(right.selceted, right.notSelected);

    return (struct SubTreeStatus) {selected, notSelected};
}

int rob(struct TreeNode* root){
    struct SubTreeStatus rootStatus = dfs(root);

    return fmax(rootStatus.selceted, rootStatus.notSelected);
}

// @lc code=end

