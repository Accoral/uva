/*************************************************************************
    > File Name: 10913.cpp
    > Author: Coral_Peng
    > Mail: 313221234@qq.com 
    > Created Time: 2013年05月05日 星期日 14时33分13秒
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
const int MAXN = 80;
int mat[MAXN][MAXN], dp[MAXN][MAXN][6][3], N, k, vis[MAXN][MAXN][6][3];
int dx[] = { 0, 0, +1 }; // left, right, down
int dy[] = { -1, +1, 0 };
int dfs ( int x, int y, int cnt, int v ) {
	int &ans = dp[x][y][cnt][v];
	if ( vis[x][y][cnt][v] ) return ans;
	vis[x][y][cnt][v] = 1;

	if ( mat[x][y] < 0 ) cnt++;
	ans = mat[x][y];

	if ( cnt <= k ) {
		if ( x == N && y == N ) return ans;
	}
	else if ( cnt > k ) return ans = INF;

	int tmp = -INF, count = 0;
	if ( v == 0 ) {
		if ( y+1 <= N && dfs ( x,y+1,cnt,0 ) != INF ) tmp = max ( tmp, dfs ( x, y+1, cnt, 0 ) ), ++count;
		if ( x+1 <= N && dfs ( x+1,y,cnt,2 ) != INF ) tmp = max ( tmp, dfs ( x+1, y, cnt, 2 ) ), ++count;
	}
	else if ( v == 1 ) {
		if ( 1 <= y-1 && dfs ( x,y-1,cnt,1 ) != INF ) tmp = max ( tmp, dfs ( x, y-1, cnt, 1 ) ), ++count;
		if ( x+1 <= N && dfs ( x+1,y,cnt,2 ) != INF ) tmp = max ( tmp, dfs ( x+1, y, cnt, 2 ) ), ++count;
	}
	else {//v == 2
		if ( y+1 <= N && dfs ( x,y+1,cnt,0 ) != INF ) tmp = max ( tmp, dfs ( x, y+1, cnt, 0 ) ), ++count;
		if ( 1 <= y-1 && dfs ( x,y-1,cnt,1 ) != INF ) tmp = max ( tmp, dfs ( x, y-1, cnt, 1 ) ), ++count;
		if ( x+1 <= N && dfs ( x+1,y,cnt,2 ) != INF ) tmp = max ( tmp, dfs ( x+1, y, cnt, 2 ) ), ++count;
	}

	if ( count ) ans = tmp + ans;
	else ans = INF;
	return ans;
}
int main()
{
	int i, j, T = 1;
	while ( scanf ( "%d%d", &N, &k ) != EOF ) {
		if ( !N && !k ) break;
		for ( i = 1; i <= N; ++i )
			for ( j = 1; j <= N; ++j ) scanf ( "%d", &mat[i][j] );
		memset ( vis, 0, sizeof(vis) );
		//printf ( "ans = %d\n", dfs(1,1,0,0) );
		printf ( "Case %d: ", T++ );
		if ( dfs(1,1,0,0) != INF ) printf ( "%d\n", dfs(1,1,0,0) );
		else printf ( "impossible\n" );
	}
    return 0;
}
