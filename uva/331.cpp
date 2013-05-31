#include <cstdio>
#include <algorithm>
using namespace std;
int a[7], n, ans;
bool OK ( ) {
	for ( int i = 1; i < n; ++i ) if ( a[i-1] > a[i] ) return false;
	return true;
}
void dfs ( int cur ) {
	if ( OK ( ) ) {
		++ans;
		return;
	}
	for ( int i = 0; i < n-1; ++i ) if ( a[i] > a[i+1] ) {
		swap ( a[i], a[i+1] );
		dfs ( cur+1 );
		swap ( a[i], a[i+1] );
	}
}
int main ( ) {
	int T = 1, i;
	while ( scanf ( "%d", &n ) && n ) {
		for ( i = 0; i < n; ++i ) scanf ( "%d", a+i );
		ans = 0;
		if ( !OK ( ) ) dfs ( 0 );
		printf ( "There are %d swap maps for input data set %d.\n", ans, T++ );
	}
}
