#include <cstdio>
#include <cstring>
#include <cmath>
int x[10], y[10], n, ans[10], arr[10], vis[10];
double min_sum;
double dist ( int x1, int y1, int x2, int y2 ) {
	return sqrt ( (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) );
}
void dfs ( int cur, double sum ) {
	if ( cur == n ) {
		if ( sum < min_sum ) {
			min_sum = sum;
			memcpy ( ans, arr, sizeof ( arr ) );
		}
		return;
	}
	if ( sum > min_sum ) return;
	for ( int i = 0; i < n; ++i )
		if ( !vis[i] ) {
			vis[i] = 1;
			arr[cur] = i;
			if ( cur == 0 ) dfs ( cur+1, 0 );
			else dfs ( cur+1, sum+dist( x[arr[cur]], y[arr[cur]], x[arr[cur-1]], y[arr[cur-1]] ) );
			vis[i] = 0;
		}
}
int main ( ) {
	int t = 1;
	while ( scanf ( "%d", &n ) != EOF && n ) {
		for ( int i = 0; i < n; ++i ) scanf ( "%d%d", x+i, y+i );
		min_sum = 0x7fffffff;
		memset ( vis, 0, sizeof ( vis ) );
		dfs ( 0, 0 );
		printf ( "**********************************************************\n" );
		printf ( "Network #%d\n", t++ );
		for ( int i = 1; i < n; ++i )
			printf ( "Cable requirement to connect (%d,%d) to (%d,%d) is %.2lf feet.\n",
					x[ans[i-1]], y[ans[i-1]], x[ans[i]], y[ans[i]], dist( x[ans[i-1]], y[ans[i-1]], x[ans[i]], y[ans[i]] ) + 16 );
		printf ( "Number of feet of cable required is %.2lf.\n", min_sum+(n-1)*16 );
	}
}
