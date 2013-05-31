#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;
int ans[1025][1025];
vector < pair < int, pair < int, int > > > v;
int main ( ) {
	int n, d, cases, i, j, num, max_num, x, y, k, flag;
	while ( scanf ( "%d", &cases ) != EOF ) {
		while ( cases-- ) {
			scanf ( "%d%d", &d, &n );
			memset ( ans, 0, sizeof ( ans ) );
			for ( max_num = k = 0; k < n; ++k ) {
				scanf ( "%d%d%d", &x, &y, &num );
				i = x - d;
				if ( i < 0 ) i = 0;
				for ( ; i < 1025 && i <= x + d; ++i ) {
					j = y - d;
					if ( j < 0 ) j = 0;
					for ( ; j < 1025 && j <= y + d; ++j ) {
						ans[i][j] += num;
						if ( max_num < ans[i][j] ) max_num = ans[i][j];
					}
				}
			}
			//printf ( "max=%d\n", max_num );
			flag = 1;
			for ( i = 0; flag && i < 1025; ++i )
				for ( j = 0; flag && j < 1025; ++j )
					if ( ans[i][j] == max_num ) {
						printf ( "%d %d %d\n", i, j, max_num );
						flag = 0;
					}
		}
	}
}
