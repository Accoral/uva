#include <cstdio>
#include <cstring>
int n, m, G[30][30], ans, vis[30][30];
void dfs ( int x, int sum ) {
	if ( ans < sum ) ans = sum;
	//if ( sum < ans ) return;
	for ( int i = 0; i < n; ++i )
		if ( !vis[x][i] && !vis[i][x] && G[x][i] ) {
			vis[x][i] = 1;
			dfs ( i, sum+1 );
			vis[x][i] = 0;
		}
}
int main ( ) {
	int i, x, y;
	while ( scanf ( "%d%d", &n, &m ) != EOF ) {
		if ( !n && !m ) break;
		memset ( G, 0, sizeof ( G ) );
		for ( i = 0; i < m; ++i ) {
			scanf ( "%d%d", &x, &y );
			G[x][y]++;
			G[y][x]++;
		}
		ans = 0;
		for ( i = 0; i < m; ++i ) {
			memset ( vis, 0, sizeof ( vis ) );
			dfs ( i, 0 );
		}
		//printf ( "%d:ans=%d\n", i,ans );
		printf ( "%d\n", ans );
	}
}
