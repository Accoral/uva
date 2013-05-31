#include <stdio.h>
#include <algorithm>
using namespace std;
const int MAXN = 10000 + 10;
int a[MAXN];
int main ( ) {
	int n, q, x, i, *pos, cases = 1;
	while ( scanf ( "%d%d", &n, &q ) != EOF ) {
		if ( n == 0 && q == 0 ) break;
		printf ( "CASE# %d:\n", cases++ );
		for ( i = 0; i < n; ++i ) scanf ( "%d", a + i );
		sort ( a, a + n );
		while ( q-- ) {
			scanf ( "%d", &x );
			pos = find ( a, a + n, x );
			//printf ( "pos = %d\n", pos );
			if ( pos - a == n ) printf ( "%d not found\n", x );
			else printf ( "%d found at %d\n", x, (int)(pos - a) + 1 );
		}
	}
}
