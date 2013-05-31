#include <stdio.h>
int main ( ) {
	int a[55], n, l, ans, i, j, tmp;
	while ( scanf ( "%d", &n ) != EOF ) {
		while ( n-- ) {
			scanf ( "%d", &l );
			for ( i = 0; i < l; ++i ) scanf ( "%d", a + i );
			for ( ans = i = 0; i < l; ++i )
				for ( j = i + 1; j < l; ++j )
					if ( a[i] > a[j] ) {
						//printf ( "a[i] = %d, a[j] = %d\n", a[i], a[j] );
						tmp = a[i];
						a[i] = a[j];
						a[j] = tmp;
						++ans;
					}
			printf ( "Optimal train swapping takes %d swaps.\n", ans );
		}
	}
}
