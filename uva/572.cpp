#include <stdio.h>
#include <string.h>
const int MAXN = 105;
int m, n, vis[MAXN][MAXN];
char maze[MAXN][MAXN];
void dfs ( int x, int y ) {
	if ( maze[x][y] == '*' || vis[x][y] ) return;
	vis[x][y] = 1;
	dfs ( x - 1, y - 1 ); dfs ( x - 1, y ); dfs ( x - 1, y + 1 );
	dfs ( x    , y - 1 );                   dfs ( x    , y + 1 );
	dfs ( x + 1, y - 1 ); dfs ( x + 1, y ); dfs ( x + 1, y + 1 );
}
int main ( ) {
	char s[MAXN];
	int i, j;
	while ( scanf ( "%d%d", &m, &n ) != EOF && m ) {
		memset ( maze, '*', sizeof ( maze ) );
		memset ( vis, 0, sizeof ( vis ) );
		for ( i = 0; i < m; ++i ) {
			scanf ( "%s", s );
			for ( j = 0; j < n; ++j ) maze[i+1][j+1] = s[j];
		}
		int ans = 0;
		for ( i = 1; i <= m; ++i )
			for ( j = 1; j <= n; ++j )
				if ( !vis[i][j] && maze[i][j] == '@' ) ++ans, dfs ( i, j );
		printf ( "%d\n", ans );
	}
}
