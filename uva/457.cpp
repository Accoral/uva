#include <stdio.h>
#include <string.h>
void print ( int x ) {
	char c;
	switch ( x ) {
		case 0: c = ' '; break;
		case 1: c = '.'; break;
		case 2: c = 'x'; break;
		case 3: c = 'W'; break;
	}
	printf ( "%c", c );
}
int main ( ) {
	int DNA[10], n, ans[42], old[42], flag;
	while ( scanf ( "%d", &n ) != EOF ) {
		flag = 0;
		while ( n-- ) {
			if ( flag ) printf ( "\n" );
			else flag = 1;
			for ( int i = 0; i < 10; ++i ) scanf ( "%d", DNA + i );
			memset ( ans, 0, sizeof ( ans ) );
			ans[20] = 1;
			for ( int i = 1; i <= 50; ++i ) {
				for ( int j = 1; j <= 40; ++j ) print ( ans[j] );
				printf ( "\n" );
				memcpy ( old, ans, sizeof ( ans ) );
				for ( int j = 1; j <= 40; ++j )
					ans[j] = DNA[old[j-1]+old[j]+old[j+1]];
			}
		}
	}
}
