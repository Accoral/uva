#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN = 55;
int N, G[MAXN][MAXN], degree[MAXN], vis[MAXN], cnt, p[MAXN];
void euler ( int u ) {
	for ( int v = 0; v < MAXN; ++v ) if ( G[u][v] ) {
		G[u][v]--;
		G[v][u] = G[u][v];
		euler ( v );
		printf ( "%d %d\n", v, u );
	}
}
int FIND ( int x ) {
	return p[x] == x ? x : ( p[x] = FIND ( p[x] ) );
}
int UNION ( int x, int y ) {
	x = FIND ( x ); y = FIND ( y );
	if ( x != y ) p[x] = y;
}
int main ( ) {
	int T, x, y;
	while ( scanf ( "%d", &T ) != EOF ) {
		for ( int t = 1; t <= T; ++t ) {
			if ( t ^ 1 ) printf ( "\n" );
			printf ( "Case #%d\n", t );
			scanf ( "%d", &N );
			memset ( G, 0, sizeof ( G ) );
			memset ( degree, 0, sizeof ( degree ) );
			for ( int i = 0; i < MAXN; ++i ) p[i] = i;
			for ( int i = 0; i < N; ++i ) {
				scanf ( "%d%d", &x, &y );
				degree[x]++; degree[y]++;
				G[y][x]++;
				G[x][y] = G[y][x];
				x = FIND ( x ); y = FIND ( y );
				if ( x != y ) UNION ( x, y );
			}
			int ok = 1;
			for ( int i = 0; i < MAXN; ++i ) if ( degree[i]&1 ) { ok = 0; break; }
			if ( !ok ) printf ( "some beads may be lost\n" );
			else {
				int t = FIND ( x );
				for ( int i = 0; i < MAXN; ++i ) if ( degree[i] && t != FIND ( i ) ) { ok = 0; break; }
				if ( !ok ) printf ( "some beads may be lost\n" );
				else euler ( x );
			}
		}
	}
}
