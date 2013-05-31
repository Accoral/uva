#include <cstdio>
#include <cstring>
const int MAXN = 105;
int n, m, t, topo[MAXN], G[MAXN][MAXN], c[MAXN];
void dfs ( int u ) {
	for ( int v = 1; v <= n; ++v ) if ( G[u][v] )
		if ( !c[v] ) dfs ( v );
	c[u] = 1; topo[--t] = u;
	return;
}
void toposort ( ) {
	t = n;
	memset ( c, 0, sizeof ( c ) );
	for ( int u = 1; u <= n; ++u ) if ( !c[u] )
		dfs ( u );
}
int main ( ) {
	int x, y;
	while ( scanf ( "%d%d", &n, &m ) != EOF ) {
		if ( !n && !m ) break;
		memset ( G, 0, sizeof ( G ) );
		while ( m-- ) {
			scanf ( "%d%d", &x, &y );
			G[x][y] = 1;
		}
		toposort ( );
		for ( int i = 0; i < n-1; ++i ) printf ( "%d ", topo[i] );
		printf ( "%d\n", topo[n-1] );
	}
}
