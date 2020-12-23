/*
 * @lc app=leetcode.cn id=207 lang=c
 *
 * [207] 课程表
 */

// @lc code=start
int **edges;
int *edgesColSize;
int *visited;
bool valid;

void dfs(int u) {
    visited[u] = 1; // 搜索中
    for (int i = 0; i < edgesColSize[u]; ++i){
        if (visited[edges[u][i]] == 0){
            dfs(edges[u][i]);
            if (!valid) {
                return;
            }
        } else if (visited[edges[u][i]] == 1){
            valid = false;
            return ;
        }
    }

    visited[u] = 2; // 已搜索
}

bool canFinish(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize){
    valid = true;
    edges = malloc(sizeof(int*) * numCourses);
     for (int i = 0; i < numCourses; ++i) {
        edges[i] = (int*)malloc(0);
    }

    edgesColSize = malloc(sizeof(int) * numCourses);
    visited = malloc(sizeof(int) * numCourses);
    memset(edgesColSize, 0, sizeof(int) * numCourses);
    memset(visited, 0, sizeof(int) * numCourses);

    for (int i = 0; i < prerequisitesSize; ++i){
        int a = prerequisites[i][1];
        int b = prerequisites[i][0];

        edgesColSize[a]++;
        edges[a] = (int *)realloc(edges[a], sizeof(int) * edgesColSize[a]);
        edges[a][edgesColSize[a] - 1] = b;
    }

    for (int i = 0; i < numCourses && valid; ++i){
        if (!visited[i]) {
            dfs(i);
        }
    }

    for (int i = 0; i < numCourses; ++i){
        free(edges[i]);
    }

    free(edges);
    free(edgesColSize);
    free(visited);

    return valid;
}


// @lc code=end

