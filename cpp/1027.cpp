#include<iostream>
#include<algorithm>
using namespace std;

int N;
double building[51];
int x, ans, cnt;
double gradient, memo;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	for (int i = 1; i <= N; i++)
		cin >> building[i];
	
	for (int i = 1; i <= N; i++)
	{
		cnt = 0;

		memo = 1000000000; // 10억

		for (int j = i - 1; j >= 1; j--)
		{
			gradient = (building[i] - building[j]) / ((double)i - (double)j);
			if (gradient < memo)
			{
				cnt++;
				memo = gradient;
			}
		}

		memo = -1000000000; // -10억

		for (int j = i + 1; j <= N; j++)
		{
			gradient = (building[j] - building[i]) / ((double)j - (double)i);
			if (gradient > memo)
			{
				cnt++;
				memo = gradient;
			}
		}
		ans = max(ans, cnt);

	}

	cout << ans;
}
