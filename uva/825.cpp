/*************************************************************************
    > File Name: 825.cpp
    > Author: Coral_Peng
    > Mail: 313221234@qq.com 
    > Created Time: 2013年05月06日 星期一 20时25分36秒
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
const int MAXN = 1024;
int W, N, mat[MAXN][MAXN], dp[MAXN][MAXN], vis[MAXN][MAXN];
int dx[] = { 0, +1 };
int dy[] = { +1, 0 };
int dfs ( int x, int y ) {
	int &ans = dp[x][y];
	if ( vis[x][y] ) return ans;
	vis[x][y] = 1;

	ans = 0;
	if ( x == W && y == N ) return ans = 1;
	int nx, ny, i;
	for ( i = 0; i < 2; ++i ) {
		nx = x + dx[i]; ny = y + dy[i];
		if ( 1 <= nx && nx <= W && 1 <= ny && ny <= N && mat[nx][ny] == 0 )
			ans += dfs ( nx, ny ); 
	}
	return ans;
}
int main()
{
	int i, j, T, x, y, len;
	string s;
	scanf ( "%d", &T );
	while ( T-- ) {
		scanf ( "%d%d", &W, &N );
		getline ( cin, s );
		memset ( mat, 0, sizeof(mat) );
		for ( i = 0; i < W; ++i ) {
			getline ( cin, s );
			x = 0; len = s.length ( );
			for ( j = 0; j < len && s[j] == ' '; ++j );
			for ( ; j < len && s[j] != ' '; ++j ) x = x * 10 + s[j] - '0';
			while ( j < len ) {
				while ( s[j] == ' ' && j < len ) ++j;
				y = 0;
				for ( ; j < len && s[j] != ' '; ++j ) y = y * 10 + s[j] - '0';
				if ( y ) mat[x][y] = 1;
			}
		}
		/*
		for ( i = 1; i <= W; ++i ) {
			for ( j = 1 ; j <= N; ++j ) printf ( "%d ", mat[i][j] );
			putchar('\n');
		}
		*/
		memset ( vis, 0, sizeof(vis) );
		if ( mat[1][1] ) printf ( "0\n" );
		else printf ( "%d\n", dfs ( 1, 1 ) );

		if ( T ) printf ( "\n" );
	}
    return 0;
}
