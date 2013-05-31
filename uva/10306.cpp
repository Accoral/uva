/*************************************************************************
    > File Name: 10306.cpp
    > Author: Coral_Peng
    > Mail: 313221234@qq.com 
    > Created Time: 2013年05月02日 星期四 21时55分13秒
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
const int INF = 0x7fffffff;
const int MAXN = 310;
int T, m, S, vx[45], vy[45], dp[MAXN][MAXN], vis[MAXN][MAXN];
int dfs ( int i, int j ) {
	//printf ( "%d	%d	i2+j2=%d	s*s=%d\n", i, j, i*i+j*j, S*S );
	int &ans = dp[i][j];
	if ( vis[i][j] ) return ans;
	vis[i][j] = 1;
	ans = INF;
	if ( i*i+j*j >= S*S ) {
		if ( i*i+j*j == S*S ) return ans = 0;
		else return ans = INF;
	}
	for ( int k = 0; k < m; ++k )
		if ( i+vx[k] <= S && j+vy[k] <= S && dfs(i+vx[k],j+vy[k]) != INF ) ans = min ( ans, dfs(i+vx[k],j+vy[k])+1 );
	return ans;
}
int main()
{
	int i;
	while ( scanf ( "%d", &T ) != EOF ) {
		while ( T-- ) {
			scanf ( "%d%d", &m, &S );
			for ( i = 0; i < m; ++i ) scanf ( "%d%d", vx+i, vy+i );
			memset ( vis, 0, sizeof(vis) );
			if ( dfs(0,0) == INF ) printf ( "not possible\n" );
			else printf ( "%d\n", dfs(0,0) );
		}
	}
    return 0;
}
