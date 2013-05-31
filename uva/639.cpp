#include <cstdio>
#include <cstring>
char mat[5][5];
int n, ans;
bool Canput ( int row, int col ) {
	int i;
	for ( i = row-1; i >= 0; --i ) {
		if ( mat[i][col] == 'O' ) return false;
		if ( mat[i][col] == 'X' ) break;
	}
	for ( i = col-1; i >= 0; --i ) {
		if ( mat[row][i] == 'O' ) return false;
		if ( mat[row][i] == 'X' ) break;
	}
	return true;
}
void dfs ( int k, int cur ) {
	int x, y;
	if ( k == n*n ) {
		if ( cur > ans ) {
			ans = cur;
			return;
		}
	}
	else {
		x = k / n; y = k % n;
		if ( mat[x][y] == '.' && Canput ( x, y ) ) {
			mat[x][y] = 'O';
			dfs ( k+1, cur+1 );
			mat[x][y] = '.';
		}
		dfs ( k+1, cur );
	}
}
int main ( ) {
	int i, j;
	while ( scanf ( "%d", &n ) != EOF && n ) {
		for ( i = 0; i < n; ++i )
			scanf ( "%s", mat[i] );
		ans = 0;
		dfs ( 0, 0 );
		printf ( "%d\n", ans );
	}
}
