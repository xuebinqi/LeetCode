/*
 * @lc app=leetcode.cn id=472 lang=c
 *
 * [472] 连接词
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */


struct DictTree {
    struct DictTree *childs[26];
    int isWord;
};

void initDictTree(struct DictTree **node) {
    *node = malloc(sizeof(struct DictTree));
    for (int i = 0; i < 26; ++i) {
        ((*node)->childs)[i] = NULL;
    }

    (*node)->isWord = 0;
}

void insertWord(struct DictTree *root, char *word) {
    struct DictTree *p;
    p = root;
    for (int i = 0; word[i] != '\0'; ++i) {
        if ((p->childs)[word[i] - 'a'] == NULL) {
            initDictTree(&((p->childs)[word[i] - 'a']));
        }

        p = (p->childs)[word[i] - 'a'];
        if (word[i + 1] == '\0'){
            p->isWord = 1;
        }
    }
}

int searchWord(struct DictTree *root, char *word, int start, int deep) {
    if (start == strlen(word)) {
        if (deep > 2) {
            return 1;
        }

        return 2;
    }

    struct DictTree *p = root;
    for (int i = start; word[i] != '\0'; ++i) {
        p = (p->childs)[word[i] - 'a'];
        if (p == NULL) {
            return 0;
        }

        if (p->isWord == 1) {
            int ret = searchWord(root, word, i + 1, deep + 1);
            if (ret > 0) {
                return ret;
            }
        }
    }

    return 0;
}

char ** findAllConcatenatedWordsInADict(char ** words, int wordsSize, int* returnSize){
    struct DictTree *root;
    initDictTree(&root);
    char **ret = malloc(sizeof(char *) * 1000);
    *returnSize = 0;

    for (int i = 0; i < wordsSize; ++i) {
        insertWord(root, words[i]);
    }

    for (int i = 0; i < wordsSize; ++i) {
        if (searchWord(root, words[i], 0, 1) == 1) {
            ret[*returnSize] = words[i];
            (*returnSize)++;
        }
    }

    return ret;
}
// @lc code=end

