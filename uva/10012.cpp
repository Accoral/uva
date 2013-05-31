#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
int n, vis[10];
double r[10], min_sum, coord[10], radi[10];
void dfs ( int cur ) {
	if ( cur == n ) {
		double left, right;
		left = 0x7ffffff, right = 0;
		for ( int k = 0; k < cur; ++k ) {
			left = min ( left, coord[k]-radi[k] );
			right = max ( right, coord[k]+radi[k] );
		}
		min_sum = min ( min_sum, right-left );
		return;
	}
	for ( int i = 0; i < n; ++i ) if ( !vis[i] ) {
		radi[cur] = r[i];
		coord[cur] = 0;
		for ( int k = 0; k < cur; ++k ) {
			double tmp = coord[k] + 2*sqrt(radi[k]*radi[cur]);
			coord[cur] = max ( coord[cur], tmp );
		}
		vis[i] = 1;
		dfs ( cur+1 );
		vis[i] = 0;
	}
}
int main ( ) {
	int i, T;
	while ( scanf ( "%d", &T ) != EOF ) {
		while ( T-- ) {
			scanf ( "%d", &n );
			for ( i = 0; i < n; ++i ) scanf ( "%lf", r+i );
			min_sum = 0x7fffffff;
			for ( i = 0; i < n; ++i ) {
				memset ( vis, 0, sizeof(vis) );
				radi[0] = r[i];
				coord[0] = r[i];
				vis[i] = 1;
				dfs ( 1 );
			}
			printf ( "%.3lf\n", min_sum );
		}
	}
}
