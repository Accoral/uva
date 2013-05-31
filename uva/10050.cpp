#include <stdio.h>
#include <string.h>
const int MAXN = 4000;
int a[MAXN];
int main ( ) {
	int T, n, p, x, ans;
	while ( scanf ( "%d", &T ) != EOF ) {
		while ( T-- ) {
			scanf ( "%d", &n );
			memset ( a, 0, sizeof ( a ) );
			scanf ( "%d", &p );
			while ( p-- ) {
				scanf ( "%d", &x );
				for ( int i = 1; i <= n; ++i ) if ( i % x == 0 ) a[i] = 1;
			}
			ans = 0;
			for ( int i = 6; i <= n; i += 7 ) a[i] = 0;
			for ( int i = 7; i <= n; i += 7 ) a[i] = 0;
			//for ( int i = 1; i <= n; ++i ) printf ( "%d ", a[i] );printf ( "\n" );
			for ( int i = 1; i <= n; ++i ) ans += a[i];
			printf ( "%d\n", ans );
		}
	}
}
