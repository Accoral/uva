#include <stdio.h>
#include <string.h>
int main ( ) {
	int n, i, j, ok;
	char s[85];
	scanf ( "%d", &n );
	while ( n-- ) {
		scanf ( "%s", s );
		int len = strlen ( s );
		for ( i = 1; i <= len; ++i ) 
			if ( len % i == 0 ) {
				ok = true;
				for ( j = i; s[j]; ++j ) {
					if ( s[j] != s[j % i] ) {
						ok = false;
					   	break;
					}
				}
				if ( ok ) {
					printf ( "%d\n", i );
					break;
				}
			}
		if ( n ) printf ( "\n" );
	}
}
