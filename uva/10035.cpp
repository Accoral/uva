#include <stdio.h>
int main ( ) {
	int a, b, c, ans, i;
	while ( scanf ( "%d%d", &a, &b ) !=EOF ) {
		if ( !a && !b ) break;
		for ( i = c = ans = 0; i < 10; ++i ) {
			c = ( a % 10 + b % 10 + c ) / 10;
			ans += c;
			a /= 10, b /= 10;
		}
		if ( ans == 0 ) printf ( "No carry operation.\n" );
		else if ( ans == 1 ) printf ( "1 carry operation.\n" );
		else printf ( "%d carry operations.\n", ans );
	}
}
