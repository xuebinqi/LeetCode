/*
 * @lc app=leetcode.cn id=306 lang=c
 *
 * [306] 累加数
 */

// @lc code=start

void dfs(char *num, int index, long *tmp, int tmpSize, bool *re) {
    if (tmpSize >= 3) {
        if (tmp[tmpSize - 3] + tmp[tmpSize - 2] != tmp[tmpSize - 1]) {
            return;//当暂时数组里的数字个数超过3个但不符合累加数要求，不用继续查找，直接返回
        }
    }
    if (index == strlen(num)) {//用光了字符数组里所有字符
        if (tmpSize < 3) return;//只组成了少于3个数字，肯定为假，返回
        int i = 0;
        for (i = 0; i < tmpSize - 2; i++) {//遍历暂时数组所有元素是否满足累加数要求
            if (tmp[i] + tmp[i + 1] != tmp[i + 2]) {
                break;
            }
        }
        if (i == tmpSize - 2) {//有满足的情况，将返回值改为真
            *re = true;
        }
        return;
    }
    if (num[index] == '0') {//由于不能有前导零，如果当前数字为0，那么本次取的数字只能为0
        tmp[tmpSize] = 0;
        dfs(num, index + 1, tmp, tmpSize + 1, re);
        return;
    }
    int i = 0, cnt = 0;
    long sum = 0;
    for (i = index; i < strlen(num); i++) {//一般情况
        sum = sum * 10 + num[i] - '0';
        cnt++;
        //下面这句是为了防止数字过大溢出long类型，可以轻松想到
        //如果某个数字取了大于strlen(num)/2长度的字符，就不满足tmp[i]+tmp[i+1]=tmp[i+2]这个条件
        //所以设置记数cnt，防止以上情况出现
        if (2 * cnt > strlen(num)) break;
        tmp[tmpSize] = sum;
        dfs(num, i + 1, tmp, tmpSize + 1, re);
    }
}

bool isAdditiveNumber(char *num) {
    if (strlen(num) < 3) return false;
    bool res = false;
    long tmp[strlen(num)];//暂时存放取出的n个字符组成的数字
    memset(tmp, 0, sizeof(tmp));
    dfs(num, 0, tmp, 0, &res);
    return res;
}

// @lc code=end
