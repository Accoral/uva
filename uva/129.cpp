#include <cstdio>
#include <cstring>
int n, L, s[88], cnt = 0;
int dfs ( int cur ) {
		//printf ( "cnt=%d:\n", cnt );
	if ( cnt++ == n ) {
		for ( int i = 0; i < cur; ++i ) {
			if ( i && (i%64==0) ) printf ( "\n" );
			else if ( i && (i%4==0) ) printf ( " " );
			printf ( "%c", 'A' + s[i] );
		}
		printf ( "\n%d\n", cur );
		return 0;
	}
	for ( int i = 0; i < L; ++i ) {
		s[cur] = i;
		int ok = 1;
		for ( int j = 1; j*2 <= cur+1; ++j ) {
			int equal = 1;
			for ( int k = 0; k < j; ++k )
				if ( s[cur-k] != s[cur-k-j] ) { equal = 0; break; }
			if ( equal ) { ok = 0; break; }
		}
		if ( ok ) if ( !dfs ( cur+1 ) ) return 0;
	}
	return 1;
}
int main ( ) {
	while ( scanf ( "%d%d", &n, &L ) != EOF ) {
		if ( !n && !L ) break;
		cnt = 0;
		dfs ( 0 );
	}
}
