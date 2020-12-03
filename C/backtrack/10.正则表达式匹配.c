/*
 * @lc app=leetcode.cn id=10 lang=c
 *
 * [10] 正则表达式匹配
 */

// @lc code=start

bool matchCore(char *str,char *pattern) {
	if(*str == '\0' && *pattern == '\0')
		return true;
 
	if(*str != '\0' && *pattern == '\0')
		return false;
 
	if(*(pattern + 1) == '*') {
		if(*pattern == *str || (*pattern == '.' && *str != '\0'))
			return matchCore(str + 1, pattern + 2) || // 匹配1个字符
                   matchCore(str + 1, pattern) ||     // 匹配多个字符
				   matchCore(str, pattern + 2);       // 匹配0个
		else
			return matchCore(str,pattern + 2);
	}
	
	if(*str == *pattern || (*pattern == '.' && *str != '\0'))
		return matchCore(str + 1,pattern + 1);
 
	return false;
}
bool isMatch(char * s, char * p) {
    if(s == NULL || p == NULL)
		return false;
    return matchCore(s, p);
}
// @lc code=end

