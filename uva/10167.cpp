#include <cstdio>
#include <vector>
using namespace std;
vector < pair < int, int > > v;
int main ( ) {
	int N, x, y, i, A, B, tmp;
	while ( scanf ( "%d", &N ) != EOF && N ) {
		v.clear ( );
		for ( i = 0; i < 2 * N; ++i ) {
			scanf ( "%d%d", &x, &y );
			v.push_back ( make_pair ( x, y ) );
		}
		int ok = 0, up, down;
		for ( A = -500; A <= 500 && !ok; ++A ) {
			for ( B = -500; B <= 500 && !ok; ++B ) {
				up = down = 0;
				for ( i = 0; i < v.size ( ); ++i ) {
					tmp = A*v[i].first + B*v[i].second;
					if ( tmp == 0 ) break;
					else if ( tmp > 0 ) up++;
					else down++;
				}
				if ( up == N && down == N ) {
					printf ( "%d %d\n", A, B );
					ok = 1;
				}
			}
		}
	}
}
