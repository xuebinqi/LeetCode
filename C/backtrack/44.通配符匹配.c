/*
 * @lc app=leetcode.cn id=44 lang=c
 *
 * [44] 通配符匹配
 */

// @lc code=start


bool isMatch(char * s, char * p){
    int j = 0;
    int start = 0, last = 0;
    int i = 0;
    int len = strlen(s);
    while(i < len){
        if (j < strlen(p) && (s[i] == p[j] || p[j] == '?')){
            ++i;
            ++j;
        } else if (j < strlen(p) && p[j] == '*'){
            last = i;
            start = ++j;
        } else if (start != 0){
            i = ++last;
            j = start;
        } else {
            return false;
        }
    }

    while (j < strlen(p) && p[j] == '*'){
        ++j;
    }

    return j == strlen(p);
}
// @lc code=end

