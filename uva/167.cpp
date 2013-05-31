#include <cstdio>
#include <cstring>
int T, ans, vis[3][50], mat[8][8], tot;
void dfs ( int cur, int sum ) {
	if ( cur == 8 ) {
		if ( sum > ans ) ans = sum;
		return;
	}
	for ( int i = 0; i < 8; ++i ) if ( !vis[0][i] && !vis[1][cur+i] && !vis[2][cur-i+8] ) {
		vis[0][i] = vis[1][cur+i] = vis[2][cur-i+8] = 1;
		dfs ( cur+1, sum+mat[cur][i] );
		vis[0][i] = vis[1][cur+i] = vis[2][cur-i+8] = 0;
	}
}
int main ( ) {
	int i, j;
	scanf ( "%d", &T );
	while ( T-- ) {
		for ( i = 0; i < 8; ++i ) for ( j = 0; j < 8; ++j ) scanf ( "%d", &mat[i][j] );
		memset ( vis, 0, sizeof(vis) );
		tot = ans = 0;
		dfs ( 0, 0 );
		printf ( "%5d\n", ans );
	}
}
