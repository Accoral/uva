#include <cstdio>
#include <cstring>
const int MAXN= 220;
int degree[MAXN], f[MAXN];
int FIND ( int x ) {
	return f[x] == x ? x : f[x] = FIND ( f[x] );
}
void UNION ( int x, int y ) {
	x = FIND ( x ); y = FIND ( y );
	if ( x != y ) f[x] = y;
}
int main ( ) {
	int N, R, ok, i, x, y, t, cnt;
	while ( scanf ( "%d%d", &N, &R ) != EOF ) {
		for ( i = 0; i < N; ++i ) f[i] = i;
		if ( R == 0 ) { printf ( "Not Possible\n" ); continue; }
		memset ( degree, 0, sizeof ( degree ) );
		while ( R-- ) {
			scanf ( "%d%d", &x, &y );
			degree[x]++; degree[y]++;
			if ( x != y ) UNION ( x, y );
		}
		t = f[x], ok = 1, cnt = 0;
		//for ( i = 0; i < N; ++i ) printf ( "f[%d]=%d\n", i, f[i] );
		for ( i = 0; i < N; ++i ) if ( f[i] != t && degree[i] ) { ok = 0; break; }
		for ( i = 0; i < N; ++i ) if ( degree[i]&1 ) cnt++;
		//printf ( "cnt=%d\n", cnt );
		if ( cnt ) ok = 0;
		if ( ok ) printf ( "Possible\n" );
		else printf ( "Not Possible\n" );
	}
}
