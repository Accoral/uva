#include <stdio.h>
int main ( ) {
	int c;
	bool ok = true;
	while ( ( c = getchar ( ) ) != EOF ) {
		if ( c == '"' ) {
			if ( ok ) {
				putchar ( '`' );
				putchar ( '`' );
			}
			else {
				putchar ( '\'' );
				putchar ( '\'' );
			}
			ok = !ok;
		}
		else putchar ( c );
	}
}
