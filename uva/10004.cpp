#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int MAXN = 205;
int G[MAXN][MAXN], n, color[MAXN], vis[MAXN];
void bfs ( ) {
	memset ( vis, 0, sizeof ( vis ) );
	memset ( color, 0, sizeof ( color ) );
	queue < int > q;
	q.push ( 0 );
	color[0] = 1;
	vis[0] = 1;
	while ( !q.empty ( ) ) {
		int v = q.front ( ); q.pop ( );
		for ( int u = 0; u < n; ++u ) {
			if ( G[u][v] ) {
				if ( vis[u] && color[u] == color[v] ) {
					printf ( "NOT BICOLORABLE.\n" );
					return;
				}
				else if ( !vis[u] ) {
					q.push ( u );
					color[u] = color[v] % 2 + 1;
					vis[u] = 1;
				}
			}
		}
	}
	printf ( "BICOLORABLE.\n" );
}
int main ( ) {
	int l, u, v;
	while ( scanf ( "%d", &n ) != EOF && n ) {
		scanf ( "%d", &l );
		memset ( G, 0, sizeof ( G ) );
		while ( l-- ) {
			scanf ( "%d%d", &u, &v );
			G[u][v] = G[v][u] = 1;
		}
		bfs ( );
	}
}
