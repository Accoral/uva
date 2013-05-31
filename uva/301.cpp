#include <cstdio>
#include <cstring>
int limit, n, m, start[25], destination[25], number[25], ans, station[10], vis[25];
void dfs ( int x, int sum ) {
	if ( sum > ans ) ans = sum;
	for ( int i = x; i < m; ++i ) {
		if ( !vis[i] ) {
			int ok = 1;
			for ( int k = start[i]; k < destination[i]; ++k ) if ( station[k] + number[i]> limit ) ok = 0;
			if ( ok ) {
				vis[i] = 1;
				for ( int k = start[i]; k < destination[i]; ++k ) station[k] += number[i];
				dfs ( i, sum+(destination[i]-start[i])*number[i] );
				for ( int k = start[i]; k < destination[i]; ++k ) station[k] -= number[i];
				vis[i] = 0;
			}
		}
	}
}
int main ( ) {
	int i, x, y, z;
	while ( scanf ( "%d%d%d", &limit, &n, &m ) != EOF ) {
		if ( !limit && !n && !m ) break;
		for ( i = 0; i < m; ++i ) scanf ( "%d%d%d", start+i, destination+i, number+i );
		ans = 0;
		memset ( vis, 0, sizeof ( vis ) );
		memset ( station, 0, sizeof ( station ) );
		dfs ( 0, 0 );
		printf ( "%d\n", ans );
	}
}
