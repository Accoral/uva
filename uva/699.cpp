#include <stdio.h>
#include <string.h>
const int MID = 100;
int x, ans[1000], i;
void dfs ( int n ) {
	scanf ( "%d", &x );
	//printf ( "x=%d\n", x );
	if ( x == -1 ) return;
	ans[n] += x;
	dfs ( n - 1 );
	dfs ( n + 1 );
}
int main ( ) {
	int cases = 1;
	while ( scanf ( "%d", &x ) != EOF && x != -1 ) {
		printf ( "Case %d:\n", cases++ );
		memset ( ans, 0, sizeof ( ans ) );
		ans[MID] = x;
		dfs ( MID - 1 );
		dfs ( MID + 1 );
		for ( i = 0; ans[i] == 0; ++i );
		printf ( "%d", ans[i] );
		for ( ++i; ans[i]; ++i ) printf ( " %d", ans[i] );
		printf ( "\n\n" );
	}
}
