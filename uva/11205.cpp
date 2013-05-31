#include <cstdio>
#include <vector>
#include <map>
using namespace std;
int a[105][20];
vector < int > v;
map < vector < int >, int > s;
int main ( ) {
	int T, n, N, i, j, k, cnt;
	scanf ( "%d", &T );
	while ( T-- ) {
		scanf ( "%d%d", &n, &N );
		for ( i = 0; i < N; ++i )
			for ( j = 0; j < n; ++j )
				scanf ( "%d", &a[i][j] );

		int ans = 0x7FFFFFF;
		for ( i = 0; i < (1<<n); ++i ) {
			s.clear ( );
			for ( k = 0; k < N; ++k ) {
				v.clear ( );
				for ( cnt = j = 0; j < n; ++j ) if ( i & (1<<j) ) v.push_back ( a[k][j] ), cnt++;
				if ( !v.empty ( ) ) {
					if ( s[v] ) break;
					s[v] = 1;
				}
			}
			if ( s.size ( ) == N && ans > cnt ) ans = cnt;
		}
		printf ( "%d\n", ans );
	}
}
