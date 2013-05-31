#include <stdio.h>
int main ( ) {
	int n, s, d, x, y;
	while ( scanf ( "%d", &n ) != EOF ) {
		while ( n-- ) {
			scanf ( "%d%d", &s, &d );
			x = ( s + d ) / 2, y = s - x;
			if ( x >= 0 && y >= 0 && x - y == d ) printf ( "%d %d\n", x, y );
			else printf ( "impossible\n" );
		}
	}
}
