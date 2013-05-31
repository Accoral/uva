#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <string.h>
using namespace std;
const int MAXN = 5000 + 10;
int ans[10], i, n, min_d, j, tmp;
double x[MAXN], y[MAXN], z[MAXN];
int main ( ) {
	for ( i = 0; ; ++i ) {
		scanf ( "%lf%lf%lf", x + i, y + i, z + i );
		if ( x[i] == 0 && y[i] == 0 && z[i] == 0 ) break;
	}
	n = i;
	memset ( ans, 0, sizeof ( ans ) );
	for ( i = 0; i < n; ++i ) {
		min_d = 0x7fffffff;
		for ( j = 0; j < n; ++j ) {
			if ( i == j ) continue;
			tmp = (int) ( sqrt ( ( x[i] - x[j] ) * ( x[i] - x[j] ) + ( y[i] - y[j] ) * ( y[i] - y[j] ) + ( z[i] - z[j] ) * ( z[i] - z[j] ) ) );
			if ( min_d > tmp ) min_d = tmp;
		}
		if ( min_d < 10 ) ++ans[min_d];
	}
	for ( i = 0; i < 10; ++i ) printf ( "%4d", ans[i] );
	printf ( "\n" );
}
