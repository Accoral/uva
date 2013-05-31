#include <stdio.h>
#include <stack>
using namespace std;
const int MAXN = 1000+10;
int target[MAXN];
int main ( ) {
	int n, i;
	while ( scanf ( "%d", &n ) != EOF && n ) {
		while ( 1 ) {
			scanf ( "%d", &target[1] );
			if ( target[1] == 0 ) break;
			for ( i = 2; i <= n; ++i ) scanf ( "%d", target + i );

			stack < int > s;
			int A = 1, B = 1, ok = 1;
			while ( B <= n ) {
				if ( A == target[B] ) A++, B++;
				else if ( !s.empty ( ) && s.top ( ) == target[B] ) { s.pop ( ); B++; }
				else if ( A <= n ) s.push ( A++ );
				else { ok = 0; break; }
			}
			printf ( "%s\n", ok ? "Yes" : "No" );
		}
		printf ( "\n" );
	}
}
