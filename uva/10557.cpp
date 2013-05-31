#include <cstdio>
#include <cstring>
int G[105][105], energy[105], c[105], vis[105], n, flag;
bool bfs ( int x ) {
	memset ( vis, 0, sizeof ( vis ) );
	//queue < int > q;
	//q.push ( x );
	int front = 0, rear = 0, q[105];
	q[rear++] = x;
	vis[x] = 1;
	while ( front < rear ) {
	//while ( !q.empty ( ) ) {
		//x = q.front ( ); q.pop ( );
		x = q[front++];
		for ( int i = 1; i <= n; ++i )
			if ( G[x][i] && !vis[i] ) {
				if ( !(i^n) ) return true;
				//q.push ( i );
				q[rear++] = i;
				vis[i] = 1;
			}
	}
	return false;
}
bool dfs ( int x, int cur ) {
	printf ( "x=%d	cur=%d\n", x, cur);
	if ( x == n ) return true;
	for ( int i = 1; i <= n; ++i )
		if ( G[x][i] && cur + energy[i] > 0 ) {
			if ( !c[i] ) {
				c[i] = cur + energy[i];
				//return dfs ( i, c[i] );
				if ( dfs ( i, c[i] ) ) return true;
			}
			else if ( cur + energy[i] > c[i] && bfs ( i ) ) {
				printf ( "c[%d] = %d	%d + energy[%d] = %d\n", i, c[i],cur, i,cur+energy[i] );
				return true;
			}
		}
	return false;
}
int main ( ) {
	int i, x, y;
	while ( scanf ( "%d", &n ) != EOF && n != -1 ) {
		memset ( G, 0, sizeof ( G ) );
		for ( i = 1; i <= n; ++i ) {
			scanf ( "%d%d", energy + i, &x );
			while ( x-- ) {
				scanf ( "%d", &y );
				G[i][y] = 1;
			}
		}
		memset ( c, 0, sizeof ( c ) );
		if ( dfs ( 1, 100 ) ) printf ( "winnable\n" );
		else printf ( "hopeless\n" );
	}
}
