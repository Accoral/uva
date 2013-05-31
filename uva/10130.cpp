/*************************************************************************
    > File Name: 10130.cpp
    > Author: Coral_Peng
    > Mail: 313221234@qq.com 
    > Created Time: 2013年05月01日 星期三 09时00分17秒
 ************************************************************************/

#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <climits>
#include <sstream>
#include <fstream>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <map>
#include <set>

using namespace std;
int dp[1005][35];
int main()
{
	int T, i, j, p, w, x, n, g, ans;
	scanf ( "%d", &T );
	while ( T-- ) {
		scanf ( "%d", &n );
		for ( i = 1; i <= n; ++i ) {
			scanf ( "%d%d", &p, &w );
			for ( j = 0; j <= 30; ++j ) {
				dp[i][j] = ( i == 1 ? 0 : dp[i-1][j] );
				if ( j >= w ) dp[i][j] = max ( dp[i-1][j], dp[i-1][j-w] + p );
			}
		}
		scanf ( "%d", &g );
		for ( ans = i = 0; i < g; ++i ) {
			scanf ( "%d", &x );
			ans += dp[n][x];
		}
		printf ( "%d\n", ans );
	}
    return 0;
}
