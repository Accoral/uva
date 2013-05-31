/*************************************************************************
    > File Name: 590.cpp
    > Author: Coral_Peng
    > Mail: 313221234@qq.com 
    > Created Time: 2013年05月02日 星期四 14时37分41秒
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

const int MAXN = 15;
const int MAXK = 1024;
const int INF = 0x7fffffff;

int n, k, dp[MAXN][MAXN][MAXK], vis[MAXN][MAXN][MAXK], G[MAXN][MAXN][MAXK];

int dfs ( int city_i, int city_j, int day ) {
	int &ans = dp[city_i][city_j][day];
	if ( vis[city_i][city_j][day] ) return ans;
	vis[city_i][city_j][day] = 1;
	ans = INF;
	if ( day == k ) {
		if ( city_j == n ) return ans = G[city_i][city_j][day];
		else return ans = INF;
	}
	for ( int city_k = 1; city_k <= n; ++city_k ) if ( day+1 <= k && G[city_j][city_k][day+1] ) {
		if ( dfs(city_j, city_k, day+1) != INF )
			ans = min ( ans, dfs(city_j,city_k,day+1) + G[city_i][city_j][day] );
	}
	return ans;
}
int main()
{
	int i, j, d, t = 1;
	while ( scanf ( "%d%d", &n, &k ) != EOF && n && k ) {
		printf ( "Scenario #%d\n", t++ );
		memset ( G, 0, sizeof(G) );
		for ( i = 1; i <= n; ++i ) {
			for ( j = 1; j <= n; ++j ) {
				if ( j == i ) continue;
				scanf ( "%d", &d );
				for ( int day = 1; day <= d; ++day ) scanf ( "%d", &G[i][j][day] );
				for ( int day = d+1; day <= k; ++day ) G[i][j][day] = G[i][j][day%d == 0?d:day%d];
			}
		}
		memset ( vis, 0, sizeof(vis) );
		if ( dfs(0,1,0) != INF ) printf ( "The best flight costs %d.\n", dfs(0,1,0) );
		else printf ( "No flight possible.\n" );
		printf ( "\n" );
	}
    return 0;
}
