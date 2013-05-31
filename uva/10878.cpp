#include <stdio.h>
#include <string.h>
char s[15];
int main ( ) {
	while ( fgets ( s, sizeof ( s ), stdin ) ) {
		if ( s[0] == '_' ) continue;
		int ans = 0, j = 1;
		int len = strlen ( s );
		for ( int i = len - 2; i > 0; --i ) {
		   if ( s[i] == '.' ) continue;
		   else if ( s[i] == 'o' ) ans += j, j *= 2;	   
		   else if ( s[i] == ' ' ) j *= 2;
		}
		printf ( "%c", ans );
	}
}
