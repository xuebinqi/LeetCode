/*
 * @lc app=leetcode.cn id=332 lang=c
 *
 * [332] 重新安排行程
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char* id2str[26 * 26 * 26];

int str2id(char* a) {
    int ret = 0;
    for (int i = 0; i < 3; i++) {
        ret = ret * 26 + a[i] - 'A';
    }
    return ret;
}

int cmp(const void* _a, const void* _b) {
    int **a = (int**)_a, **b = (int**)_b;
    return (*b)[0] - (*a)[0] ? (*b)[0] - (*a)[0] : (*b)[1] - (*a)[1];
}

int* vec[26 * 26 * 26];
int vec_len[26 * 26 * 26];
int* stk;
int stk_len;

void dfs(int curr) {
    while (vec_len[curr] > 0) {
        int tmp = vec[curr][--vec_len[curr]];
        dfs(tmp);
    }
    stk[stk_len++] = curr;
}

char** findItinerary(char*** tickets, int ticketsSize, int* ticketsColSize, int* returnSize) {
    memset(vec_len, 0, sizeof(vec_len));
    stk = malloc(sizeof(int) * (ticketsSize + 1));
    stk_len = 0;

    int* tickets_tmp[ticketsSize];
    for (int i = 0; i < ticketsSize; i++) {
        tickets_tmp[i] = (int*)malloc(sizeof(int) * 2);
        tickets_tmp[i][0] = str2id(tickets[i][0]);
        tickets_tmp[i][1] = str2id(tickets[i][1]);
        id2str[tickets_tmp[i][0]] = tickets[i][0];
        id2str[tickets_tmp[i][1]] = tickets[i][1];
    }
    qsort(tickets_tmp, ticketsSize, sizeof(int*), cmp);

    int add = 0;
    while (add < ticketsSize) {
        int adds = add + 1, start = tickets_tmp[add][0];
        while (adds < ticketsSize && start == tickets_tmp[adds][0]) {
            adds++;
        }
        vec_len[start] = adds - add;
        vec[start] = malloc(sizeof(int) * vec_len[start]);
        for (int i = add; i < adds; i++) {
            vec[start][i - add] = tickets_tmp[i][1];
        }
        add = adds;
    }

    dfs(str2id("JFK"));

    *returnSize = ticketsSize + 1;
    char** ret = malloc(sizeof(char*) * (ticketsSize + 1));
    for (int i = 0; i <= ticketsSize; i++) {
        ret[ticketsSize - i] = id2str[stk[i]];
    }
    return ret;
}
// @lc code=end

