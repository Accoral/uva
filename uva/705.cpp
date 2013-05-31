#include <cstdio>
#include <cstring>
int maze[80*2][80*2], vis[80*2][80*2], cnt, ok, ans, k, last_x, last_y;
void dfs ( int x, int y ) {
	if ( maze[x][y] == 1 || vis[x][y] ) return;
	++cnt;
	vis[x][y] = 1;
	last_x = x, last_y = y;
	if ( (x&1) ^ (y&1) ) dfs ( x - 1, y - 1 ),dfs ( x + 1, y + 1 );
	else dfs ( x - 1, y + 1 ),dfs ( x + 1, y - 1 );
	dfs ( x - 1, y ); dfs ( x, y - 1 ); dfs ( x, y + 1 ); dfs ( x + 1, y );
}
bool judge ( int x1, int y1, int x2, int y2 ) {
	int dis = ( x1 - x2 ) * ( x1 - x2 ) + ( y1 - y2 ) * ( y1 - y2 );
	return dis == 1 || dis == 2;
}
int main ( ) {
	int w, h, i, j, n = 0;
	char s[80];
	while ( scanf ( "%d%d", &w, &h ) != EOF ) {
		if ( !w && !h ) break;
		printf ( "Maze #%d:\n", ++n );
		for ( i = 0; i < 80*2; ++i )
			for ( j = 0; j < 80*2; ++j ) maze[i][j] = 1;
		memset ( vis, 0, sizeof ( vis ) );
		for ( int x = 1; x <= h; ++x ) {
			scanf ( "%s", s );
			for ( int y = 0; y <= strlen ( s ); ++y )
				if ( s[y] == '/' ) {
					maze[x*2][y*2+2] = 0; maze[x*2][y*2+3] = 1;
					maze[x*2+1][y*2+2] = 1; maze[x*2+1][y*2+3] = 0;
				}
				else if ( s[y] == '\\' ) {
					maze[x*2][y*2+2] = 1; maze[x*2][y*2+3] = 0;
					maze[x*2+1][y*2+2] = 0; maze[x*2+1][y*2+3] = 1;
				}
		}
		//for ( i = 2; i < 2 * h+3; ++i ) { for ( j = 2; j < 2 * w+3; ++j ) printf ( "%d", maze[i][j] ); printf ( "\n" ); }
		ans = k = 0;
		for ( i = 2; i < 2 * h+2; ++i ) {
			for ( j = 2; j < 2 * w+2; ++j ) 
				if ( maze[i][j] == 0 && !vis[i][j] ) {
					cnt = ok = 0;
					dfs ( i, j );
					if ( cnt > 2 && judge ( i, j, last_x, last_y ) ) ok = 1;
					if ( ok ) {
						++k;
						if ( ans < cnt ) ans = cnt;
					}
				}
		}
		if ( k == 0 ) printf ( "There are no cycles.\n" );
		else printf ( "%d Cycles; the longest has length %d.\n", k, ans );
		printf ( "\n" );
	}
}
