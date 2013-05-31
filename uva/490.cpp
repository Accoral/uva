#include <stdio.h>
#include <string.h>
char s[105][105];
int main ( ) {
	int n = 0, max_n = 0;
	while ( 1 ) {
		if ( NULL == fgets ( s[n], sizeof ( s[n] ), stdin ) ) break;
		if ( max_n < strlen ( s[n] ) ) max_n = strlen ( s[n] );
		++n;
	}
	for ( int j = 0; j < max_n - 1; ++j ) {
		for ( int i = n - 1; i >= 0; --i )
			if ( j >= strlen ( s[i] ) - 1 ) printf ( " " );
			else printf ( "%c", s[i][j] );
		printf ( "\n" );
	}
}
