#include <cstdio>
int main ( ) {
	int T, n, m, i, j;
	scanf ( "%d", &T );
	while ( T-- ) {
		scanf ( "%d%d", &n, &m );
		for ( i = 1; i < (1<<n); ++i ) {
			int k = i, a[32], cnt = 0;
			for ( j = 0; j < n; ++j ) { a[j] = k&1; cnt += a[j]; k >>= 1; }
			if ( cnt == m ) {
				for ( j = n-1; j >= 0; --j ) printf ( "%d", a[j] );
				printf ( "\n" );
			}
		}
		if ( T ) printf ( "\n" );
	}
}
