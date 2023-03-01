#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; ++i)
#define REP(i, n) for (int i = 1; i <= n; ++i)
using namespace std;

const int MAXR = 750 + 5;

int R, C, ans, arr[MAXR][MAXR], rcache[MAXR][MAXR], lcache[MAXR][MAXR];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
#endif
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> R >> C;
    REP(i, R)
    REP(j, C) {
        char x;
        cin >> x;
        arr[i][j] = (x == '1' ? 1 : 0);
    }
    for (int i = R; i >= 1; --i)
        for (int j = C; j >= 1; --j) {
            if (!arr[i][j]) continue;
            rcache[i][j] = rcache[i + 1][j + 1] + arr[i][j];
        }

    for (int i = R; i >= 1; --i)
        for (int j = C; j >= 1; --j) {
            if (!arr[i][j]) continue;
            lcache[i][j] = lcache[i + 1][j - 1] + arr[i][j];
        }

    for (int len = 375; ~len; --len) {
        REP(i, R) {
            if (i + 2 * len - 2 <= R) {
                REP(j, C) {
                    if (j - len + 1 >= 1 && j + len - 1 <= C) {
                        if (rcache[i][j] >= len && lcache[i + len - 1][j + len - 1] >= len && lcache[i][j] >= len && rcache[i + len - 1][j - len + 1] >= len) {
                            cout << len;
                            return 0;
                        }
                    }
                }
            }
        }
    }
    cout << ans;
    return 0;
}
