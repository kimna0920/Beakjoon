#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define xx first
#define yy second

string s;
const int lineCnt[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 5};
int dp[16][110][2];

int solve(int pos, int left, bool bigger){
	if(left < 0) return 10;
	if(pos == s.size()) return (bigger && !left ? 0 : 10);
	int &ret = dp[pos][left][bigger];
	if(ret != -1) return ret;

	ret = 10;
	for(int i=(bigger ? 0 : s[pos]-'0'); i<=9; ++i){
		int next = solve(pos+1, left - lineCnt[i], bigger || (i > s[pos]-'0'));
		if(next != 10){
			ret = i;
			break;
		}
	}
	return ret;
}

ll goRet;
ll go(int pos, int left, bool bigger){
	if(pos == s.size()) return 0;
	int &ret = dp[pos][left][bigger]; 
	goRet = goRet * 10 + ret;
	go(pos+1, left - lineCnt[ret], bigger || (ret > s[pos]-'0'));
}

ll tenPow(int a){
	return (a ? 10 * tenPow(a-1) : 1);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string input;
	cin >> input;
	
	int sum = 0;
	for(char &c : input)
		sum += lineCnt[c - '0'];


	memset(dp, -1, sizeof(dp));
	s = string(input.size(), '0');
	solve(0, sum, 0);
	goRet = 0;
	go(0, sum, 0);
	ll ans = goRet - stoll(input) + tenPow(s.size());


	memset(dp, -1, sizeof(dp));
	s = input;
	if(solve(0, sum, 0) != 10){
		goRet = 0;
		go(0, sum, 0);
		ans = goRet - stoll(input);
	}

	cout << ans;
}
