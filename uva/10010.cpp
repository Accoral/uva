#include <stdio.h>
#include <string.h>
#include <ctype.h>
char a[55][55], s[2555];
int m, n;
int judge ( int x, int y ) {
	int len = strlen ( s ), L_count, R_count, U_count, D_count, LU_count, RU_count, LD_count, RD_count;
	L_count = R_count = U_count = D_count = LU_count = RU_count = LD_count = RD_count = 0;
	for ( int i = 0; i < len; ++i ) { 
		if ( y - i >= 0 && a[x][y-i] == s[i] ) ++L_count;//L
		if ( y + i < n && a[x][y+i] == s[i] ) ++R_count;//R
		if ( x - i >= 0 && a[x-i][y] == s[i] ) ++U_count;//U
		if ( x + i < n && a[x+i][y] == s[i] ) ++D_count;//D
		if ( x - i >= 0 && y - i >= 0 && a[x-i][y-i] == s[i] ) ++LU_count;//LU
		if ( x - i >= 0 && y + i < n && a[x-i][y+i] == s[i] ) ++RU_count;//RU
		if ( x + i < n && y - i >= 0 && a[x+i][y-i] == s[i] ) ++LD_count;//LD
		if ( x + i < n && y + i < n && a[x+i][y+i] == s[i] ) ++RD_count;//RD
	}
	//printf ( "x=%d	y=%d:	L_count=%d,R_count=%d,U_count=%d,D_count=%d,LU_count=%d,RU_count=%d,LD_count=%d,RD_count=%d\n", x, y, L_count,R_count,U_count,D_count,LU_count,RU_count,LD_count,RD_count );
	if ( L_count == len || 
			R_count == len ||
			U_count == len ||
			D_count == len ||
			LU_count == len ||
			RU_count == len ||
			LD_count == len ||
			RD_count == len )
		return 1;
	return 0;
}
int main ( ) {
	int cases, first = 0, k, ok;
	while ( scanf ( "%d", &cases ) != EOF ) {
		while ( cases-- ) {
			if ( first ) printf ( "\n" );
			else first = 1;
			scanf ( "%d%d", &m, &n );
			for ( int i = 0; i < m; ++i ) scanf ( "%s", a[i] );
			for ( int i = 0; i < m; ++i )
				for ( int j = 0; j < n; ++j )
					a[i][j] = tolower ( a[i][j] );
			scanf ( "%d", &k );
			while ( k-- ) {
				scanf ( "%s", s );
				for ( int i = 0; s[i]; ++i ) s[i] = tolower ( s[i] );
				ok = 0;
				for ( int i = 0; i < m; ++i )
					for ( int j = 0; j < n; ++j )
						if ( !ok && judge ( i, j ) ) {
							printf ( "%d %d\n", i + 1, j + 1 );
							ok = 1;
						}
			}
		}
	}
}
