#include <cstdio>
#include <cstring>
typedef long long ll;

const ll inf = 0x3f3f3f3f3f3f3f3f;

int n;
ll k, dp[55][105][2];

ll go(int now, int sum, int isWrong) {
    if (now == n) {
        return isWrong || sum!=50;
    }
    ll &ret = dp[now][sum][isWrong];
    if (ret != inf) {
        return ret;
    }
    return ret = go(now+1, sum+1, isWrong)
               + go(now+1, sum-1, isWrong || sum <= 50);
}

void gogo(int now, int sum, int isWrong) {
    if (now == n) {
        return;
    }
    if (dp[now+1][sum+1][isWrong] >= k) {
        if (now == n-1 && k == 2) putchar(')');
        else putchar('(');
        gogo(now+1, sum+1, isWrong);
    }
    else {
        putchar(')');
        k -= dp[now+1][sum+1][isWrong];
        gogo(now+1, sum-1, isWrong || sum <= 50);
    }
}

int main() {
    scanf("%d %lld", &n, &k); k++;
    
    memset(dp, 0x3f, sizeof(dp));
    go(0, 50, 0);
    
    if (dp[0][50][0] < k) {
        return !puts("-1");
    }
    gogo(0, 50, 0);
    
    return 0;
}
