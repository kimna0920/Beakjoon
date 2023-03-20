#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;

#define INF 987654321;

int num;

int map[16][16];
int cache[16][(1 << 17) + 1][10];

int dfs(int cur, int visited, int prePrice)
{
    int& ret = cache[cur][visited][prePrice];

    if (visited == (1 << num) - 1)
        return ret = 1;

    if (ret != 0)
        return ret;

    ret = 1;

    for (int next = 0; next < num; next++)
    {
        if (visited & (1 << next))
            continue;

        if (next == cur)
            continue;
        if (map[cur][next] >= prePrice)
            ret = max(ret, dfs(next, (visited | 1 << next), map[cur][next]) + 1);
    }

    return ret;
}

void solve()
{
    cout << dfs(0, 1, 0) << endl;
}

int main()
{
    cin >> num;

    for (int i = 0; i < num; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < num; j++)
        {
            map[i][j] = s[j] - '0';
        }
    }

            
    solve();
    return 0;
}
