#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
vector < int > u;
int G[105][105], n, k, ans, v[105], color[105];
void dfs ( int cur, int sum ) {
	//printf ("this:");for ( int x = 1; x <= n; ++x ) if ( color[x] ) printf ( "%d ", x );printf ( "sum=%d	cur=%d\n", sum ,cur);
	if ( cur > n ) {
		if ( ans < sum ) {
			ans = sum;
			memcpy ( v, color, sizeof(color) );
		}
		return;
	}
	if ( cur+ n-cur + 1 <= ans ) return;
	int ok = 1;
	for ( int j = 1; j <= n; ++j ) if ( color[j] && G[cur][j] ) { ok = 0; break; }
	if ( ok ) {
		color[cur] = 1;
		dfs ( cur+1, sum+1 );
		color[cur] = 0;
	}
	dfs ( cur+1, sum );
}
int main ( ) {
	int m, x, y, i, k;
	scanf ( "%d", &m );
	while ( m-- ) {
		scanf ( "%d%d", &n, &k );
		memset ( G, 0, sizeof(G) );
		for ( i = 0; i < k; ++i ) {
			scanf ( "%d%d", &x, &y );
			G[x][y] = G[y][x] = 1;
		}
		ans = 0;
		memset ( color, 0, sizeof(color) );
		dfs ( 1, 0 );
		printf ( "%d\n", ans );
		for ( u.clear(), i = 1; i <= n; ++i ) if ( v[i] ) u.push_back ( i );
		for ( i = 0; i < u.size()-1; ++i ) printf ( "%d ", u[i] );
		printf ( "%d\n", u[i] );
	}
}
