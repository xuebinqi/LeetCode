/*
 * @lc app=leetcode.cn id=872 lang=c
 *
 * [872] 叶子相似的树
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

int nums1[205];
int nums2[205];
int idx;


void dfs(struct TreeNode *root, int *nums){
    if (!root) return;
    
    if (root ->left == NULL && root->right == NULL){
        nums[idx++] = root->val;
    }else{
        dfs(root->left, nums);
        dfs(root->right, nums);
    }  
}

bool leafSimilar(struct TreeNode* root1, struct TreeNode* root2){
    if (!root1 && !root2) return true;
    if (!root1 || !root2) return false;
    
    for(int i = 0; i < 205; ++i){
        nums1[i] = -1;
        nums2[i] = -1;
    }

    idx = 0;
    dfs(root1, &nums1);

    idx = 0;
    dfs(root2, &nums2);
    for (int i = 0; i <= idx; ++i){
        if (nums1[i] != nums2[i]){
            return false;
        }
    }
    
    return true;
}
// @lc code=end

