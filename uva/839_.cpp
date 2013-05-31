#include <stdio.h>
int flag;
int dfs ( ) {
	int wl, dl, wr, dr;
	scanf ( "%d%d%d%d", &wl, &dl, &wr, &dr );
	if ( wl == 0 ) wl = dfs ( );
	if ( wr == 0 ) wr = dfs ( );
	if ( wl*dl != wr*dr ) flag = 0;
	return wl + wr;
}
int main ( ) {
	int cases, first;
	while ( scanf ( "%d", &cases ) != EOF ) {
		first = 0;
		while ( cases-- ) {
			if ( first ) printf ( "\n" );
			else first = 1;
			flag = 1;
			dfs ( );
			if ( flag ) printf ( "YES\n" );
			else printf ( "NO\n" );
		}
	}
}
