/*
 * @lc app=leetcode.cn id=473 lang=c
 *
 * [473] 火柴拼正方形
 */

// @lc code=start

int *flag;
int gTarget;
bool dfs(int *nums, int numsSize, int index, int count, int target){
    bool ret = false;
    for (int i = index; i < numsSize; ++i) {
        if (target < nums[i]) {
            break;
        } else if (flag[i] == 1) {
            continue;
        }

        if (nums[i] == target) {
            if (count + 1 == 4) {
                return true;
            } else {
                flag[i] = 1;
                ret = dfs(nums, numsSize, 0, count + 1, gTarget);
                if (ret == true) {
                    break;
                }

                flag[i] = 0;
            }
        } else {
            int newTarget = target - nums[i];
            flag[i] = 1;
            ret = dfs(nums, numsSize, i + 1, count, newTarget);
            if (ret == true) {
                break;
            }
            flag[i] = 0;
        }
    }

    return ret;
}

int compare(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

bool makesquare(int* nums, int numsSize){
    if (numsSize < 4) return false;
    int sum = 0; 
    for (int i = 0; i < numsSize; ++i) {
        sum += nums[i];
    }

    if (sum % 4) return false;
    gTarget = sum / 4;
    qsort(nums, numsSize, sizeof(int), compare);

    flag = malloc(sizeof(int) * numsSize);
    memset(flag, 0, sizeof(int) * numsSize);
    bool ret = dfs(nums, numsSize, 0, 0, gTarget);
    return ret;
}


// @lc code=end

