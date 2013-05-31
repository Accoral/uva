#include <cstdio>
#include <cstring>
int a[6], ok, vis[6];
void dfs ( int cur, int res ) {
	if ( cur == 5 && res == 23 ) ok = 1;
	if ( cur >= 5 || ok ) return;
	for ( int i = 0; i < 5; ++i ) if ( !vis[i] ) {
		vis[i] = 1;
		dfs ( cur+1, res+a[i] );
		dfs ( cur+1, res-a[i] );
		dfs ( cur+1, res*a[i] );
		vis[i] = 0;
	}
}
int main ( ) {
	while ( scanf ( "%d%d%d%d%d", a+0, a+1, a+2, a+3, a+4 ) != EOF ) {
		if ( !a[0] && !a[1] && !a[2] && !a[3] && !a[4] ) break;
		ok = 0;
		for ( int i = 0; i < 5; ++i ) {
			memset ( vis, 0, sizeof(vis) );
			vis[i] = 1;
			dfs ( 1, a[i] );
		}
		if ( ok ) printf ( "Possible\n" );
		else printf ( "Impossible\n" );
	}
}
