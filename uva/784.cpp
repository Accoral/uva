#include <stdio.h>
#include <string.h>
char maze[35][85];
void dfs ( int x, int y ) {
	if ( maze[x][y] != ' ' ) return;
	maze[x][y] = '#';
	dfs ( x - 1, y     ); dfs ( x + 1, y     );
	dfs ( x    , y - 1 ); dfs ( x    , y + 1 );
}
int main ( ) {
	char s[85];
	int N, i, j;
	while ( scanf ( "%d\n", &N ) != EOF ) {
		while ( N-- ) {
			int n = 0, x, y, flag = 0, len;
			while ( 1 ) {
				fgets ( s, 85, stdin );
				len = strlen ( s ) - 1;
				for ( j = 0; j < len; ++j ) {
					maze[n][j] = s[j];
					if ( !flag && s[j] == '*' ) x = n, y = j, flag = 1;
				}
				maze[n][j] = '\0';
				++n;
				if ( s[0] == '_' ) break;
			}
			maze[x][y] = ' ';
			dfs ( x, y );
			for ( i = 0; i < n; ++i ) {
				len = strlen ( maze[i] );
				for ( j = 0; j < len; ++j )
					printf ( "%c", maze[i][j] );
				printf ( "\n" );
			}
		}
	}
}
