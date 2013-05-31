#include <algorithm>
#include <cstdio>
using namespace std;
int main ( ) {
	int T, n, h, i;
	scanf ( "%d", &T );
	while ( T-- ) {
		scanf ( "%d%d", &n, &h );
		char s[20];
		for ( i = 0; i < n-h; ++i ) s[i] = '0';
		for ( ; i < n; ++i ) s[i] = '1';
		do {
			for ( i = 0; i < n; ++i ) printf ( "%c", s[i] );
			printf ( "\n" );
		} while ( next_permutation ( s, s + n ) );
		if ( T ) printf ( "\n" );
	}
}
