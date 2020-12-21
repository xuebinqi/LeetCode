/*
 * @lc app=leetcode.cn id=133 lang=c
 *
 * [133] 克隆图
 */

// @lc code=start
/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     int numNeighbors;
 *     struct Node** neighbors;
 * };
 */

struct Node **visited;

struct Node*dfs(struct Node*s) {
    if (!s) return NULL;
    // 如果该节点已经被访问过了，则直接从哈希表中取出对应的克隆节点返回
    if (visited[s->val]){
        return visited[s->val];
    }

    // 克隆节点，注意到为了深拷贝我们不会克隆它的邻居的列表
    struct Node*cloneNode = (struct Node*)malloc(sizeof(struct Node));
    cloneNode->val = s->val;
    cloneNode->numNeighbors = s->numNeighbors;

    // 哈希表存储
    visited[cloneNode->val] = cloneNode;
    cloneNode->neighbors = (struct Node**)malloc(sizeof(struct Node*) * cloneNode->numNeighbors);

    // 遍历该节点的邻居并更新克隆节点的邻居列表
    for (int i = 0; i < cloneNode->numNeighbors; ++i){
        cloneNode->neighbors[i] = dfs(s->neighbors[i]);
    }

    return cloneNode;
}


struct Node *cloneGraph(struct Node *s) {
	visited = (struct Node **)malloc(sizeof(struct Node*) * 105);
    memset(visited, 0, sizeof(struct Node *) * 105);
    return dfs(s);
}
// @lc code=end

