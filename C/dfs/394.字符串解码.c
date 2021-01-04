/*
 * @lc app=leetcode.cn id=394 lang=c
 *
 * [394] 字符串解码
 */

// @lc code=start

char *dfs(char *s, char **e) {
    char *ret = (char*) malloc(sizeof(char) * 5000);
    char *buf, *end = NULL;
    int count = 0;
    int index = 0;
    while (*s != '\0'){
        if (isalpha(*s)) {
            ret[index++] = *s;
        }
        else if (isdigit(*s)) {
            count = count * 10 + (*s) - '0';
        } else if (*s == '[') {
            buf = dfs(s + 1, &end);
            while (count) {
                strcpy(ret + index, buf);
                index += strlen(buf);
                --count;
            }
            s = end;
        } else if (*s == ']') {
            *e = s;
            ret[index] = '\0';
            return ret;
        }
        ++s;
    }

    ret[index] = '\0';
    return ret;
}


char * decodeString(char * s){
    char *end = NULL;
    return dfs(s, &end);
}
// @lc code=end

