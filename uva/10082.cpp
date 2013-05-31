#include <stdio.h>
const char *str = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
int main ( ) {
	int i, c;
	while ( ( c = getchar ( ) ) != EOF ) {
		for ( i = 0; str[i] && c != str[i]; ++i );
		if ( str[i] ) putchar ( str[i - 1] );
		else putchar ( c );
	}
}
