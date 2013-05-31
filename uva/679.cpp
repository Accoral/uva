#include <stdio.h>
int n, D, I, i, ans;
int main ( ) {
	while ( scanf ( "%d", &n ) != EOF && n != -1 ) {
		while ( n-- ) {
			scanf ( "%d%d", &D, &I );
			ans = 1;
			for ( i = 0; i < D - 1; ++i )
				if ( I % 2 ) ans *= 2, I = ( I + 1 ) / 2;
				else ans = ans * 2 + 1, I /= 2;
			printf ( "%d\n", ans );
		}
	}
}
