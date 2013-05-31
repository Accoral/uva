#include <cstdio>
#include <cstring>
int fire, G[21][21], vis[21], ans[21], sum, f[21];
int FIND ( int x ) {
	return f[x] == x ? x : f[x] = FIND ( f[x] );
}
void UNION ( int x, int y ) {
	x = FIND ( x ); y = FIND ( y );
	if ( x != y ) f[x] = y;
}
void dfs ( int cnt, int x ) {
	if ( x == fire ) {
		for ( int i = 1; i < cnt; ++i ) printf ( "%d ", ans[i] );
		printf ( "%d\n", ans[cnt] );
		++sum;
		return;
	}
	//printf ( "x=%d	fire=%d	f[x]=%d f[fire]=%d\n", x, fire, FIND(x), FIND(fire) );
	if ( FIND ( x ) != FIND ( fire ) ) return;
	for ( int i = 1; i < 21; ++i ) {
		if ( !vis[i] && G[x][i] ) {
			vis[i] = 1;
			ans[cnt+1] = i;
			dfs ( cnt+1, i );
			vis[i] = 0;
		}
	}
}
int main ( ) {
	int x, y, t = 1, i;
	while ( scanf ( "%d", &fire ) != EOF ) {
		printf ( "CASE %d:\n", t++ );
		memset ( G, 0, sizeof(G) );
		for ( i = 1; i < 21; ++i ) f[i] = i;
		while ( 1 ) {
			scanf ( "%d%d", &x, &y );
			if ( !x && !y ) break;
			G[x][y] = G[y][x] = 1;
			UNION ( x, y );
		}
		memset ( vis, 0, sizeof(vis) );
		vis[1] = 1;
		ans[1] = 1;
		sum = 0;
		dfs ( 1, 1 );
		printf ( "There are %d routes from the firestation to streetcorner %d.\n", sum, fire );
	}
}
