#include <cstdio>
#include <cstring>
int n, ans[40], isp[40], vis[40];
int is_prime ( int x ) {
	for ( int i = 2; i*i <= x; ++i ) if ( x % i == 0 ) return 0;
	return 1;
}
void dfs ( int cur ) {
	if ( cur == n && isp[ans[0]+ans[n-1]] ) {
		for ( int i = 0; i < n-1; ++i ) printf ( "%d ", ans[i] );
		printf ( "%d\n", ans[n-1] );
	}
	else for ( int i = 2; i <= n; ++i )
		if ( !vis[i] && isp[i+ans[cur-1]] ) {
			ans[cur] = i;
			vis[i] = 1;
			dfs ( cur + 1 );
			vis[i] = 0;
		}
}
int main ( ) {
	int t = 0;
	while ( scanf ( "%d", &n ) != EOF ) {
		if ( t ) printf ( "\n" );
		printf ( "Case %d:\n", ++t );
		for ( int i = 2; i <= n*2; ++i ) isp[i] = is_prime ( i );
		memset ( vis, 0, sizeof ( vis ) );
		ans[0] = 1;
		dfs ( 1 );
	}
}
