#include <stdio.h>
#include <string.h>
#include <ctype.h>
char s[140];
int i, len, n;
int main ( ) {
	while ( fgets ( s, 140, stdin ) ) {
		len = strlen ( s );
		n = 0;
		for ( i = 0; i < len; ++i ) {
			//printf ( "%d: %c\n", i, s[i] );
			if ( isdigit ( s[i] ) ) n += s[i] - '0';
			else if ( s[i] == '!' ) printf ( "\n" );
			else {
				if ( s[i] == 'b' ) while ( n-- ) printf ( " " );
				else while ( n-- ) printf ( "%c", s[i] );
				n = 0;
			}
			if ( i == len - 1 ) printf ( "\n" );
		}
	}
}
