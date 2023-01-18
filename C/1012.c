#include <stdio.h>
#include <string.h>
 
int field[50][50], m, n;
 
int dfs(int x, int y) {
    field[x][y] = 0;
 
    if (x + 1 < m && field[x + 1][y] == 1) dfs(x + 1, y);
    if (x - 1 >= 0 && field[x - 1][y] == 1) dfs(x - 1, y);
    if (y + 1 < n && field[x][y + 1] == 1) dfs(x, y + 1);
    if (y - 1 >= 0 && field[x][y - 1] == 1) dfs(x, y - 1);
    return 0;
}
 
int main() {
    int T;
    scanf("%d", &T);
 
    int k, x, y, cnt;
    for (int test_case = 0; test_case < T; test_case++) {
        memset(field, 0, sizeof(field));
        scanf("%d %d %d", &m, &n, &k);
 
        while (k--) {
            scanf("%d %d", &x, &y);
            field[x][y] = 1;
        }
 
        cnt = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (field[i][j] == 1) {
                    dfs(i, j);
                    cnt++;
                }
            }
        }

        printf("%d\n", cnt);
    }
    return 0;
}
