/*
 * @lc app=leetcode.cn id=1022 lang=c
 *
 * [1022] 从根到叶的二进制数之和
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


int res;

void dfs(struct TreeNode *root, int sum){
    if (root) {
        sum  = sum * 2 + root->val;

        if (!root->left && !root->right){
            res += sum;
        }
        else{
            dfs(root->left, sum);
            dfs(root->right, sum);
        }
    }
}

int sumRootToLeaf(struct TreeNode* root){
    res = 0;
    dfs(root, 0);
    
    return res % INT_MAX;
}
// @lc code=end

