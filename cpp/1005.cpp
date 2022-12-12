#include <stdio.h>
#include <cstring>
using namespace std;

int T, N, K, W;	// 테스트케이스, 건물, 규칙, 목표건물
int D[1001]; // 건설시간
int dp[1001]; // 건설시간 메모
int preceding[1001][1001]; // 건설순서

int erection(int x)
{
	if (dp[x] >= 0) return dp[x];
	int max = 0;
	int time;
	for (int i = 1; i <= N; ++i)
	{
		if (preceding[i][x] == 1)
		{
			if (dp[i] >= 0) time = dp[i];
			else time = erection(i);
			
			if (time > max) max = time;
		}
	}
	return dp[x] = max + D[x];
}

int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d %d", &N, &K);

		memset(D, 0, sizeof(D));
		memset(dp, -1, sizeof(dp));
		memset(preceding, 0, sizeof(preceding));
		
		for (int i = 1; i <= N; i++)
			scanf("%d", &D[i]);
		
		
		int X, Y;		
		for (int i = 1; i <= K; i++) {
			scanf("%d %d", &X, &Y);
			preceding[X][Y] = 1;
		}

		scanf("%ld", &W);
		printf("%d\n", erection(W));
	}

	return 0;
}
