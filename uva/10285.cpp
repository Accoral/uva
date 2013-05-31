/*************************************************************************
    > File Name: 10285.cpp
    > Author: Coral_Peng
    > Mail: 313221234@qq.com 
    > Created Time: 2013年05月01日 星期三 09时16分18秒
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
int dp[128][128], dx[] = { -1, 1, 0, 0 }, dy[] = { 0, 0, -1, 1 }, mat[128][128];
int R, C;
int dfs ( int x, int y ) {
	int &ans = dp[x][y];
	if ( ans != -1 ) return ans;
	ans = 1;
	int nx, ny;
	for ( int i = 0; i < 4; ++i ) {
		nx = x+dx[i]; ny = y+dy[i];
		if ( 0 <= nx && nx < R && 0 <= ny && ny < C )
			if ( mat[nx][ny] < mat[x][y] ) ans = max ( ans, dfs(nx, ny) + 1 );
	}
	return ans;
}
int main()
{
	int T, i, j, ans, tmp;
	char name[100];
	scanf ( "%d", &T );
	while ( T-- ) {
		scanf ( "%s%d%d", name, &R, &C );
		for ( i = 0; i < R; ++i ) for ( j = 0; j < C; ++j ) scanf ( "%d", &mat[i][j] );
		memset ( dp, -1, sizeof(dp) );
		for ( ans = i = 0; i < R; ++i ) {
			for ( j = 0; j < C; ++j ) {
				tmp = dfs ( i, j );
				ans = max ( ans, tmp );
			}
		}
		printf ( "%s: %d\n", name, ans );
	}
    return 0;
}
