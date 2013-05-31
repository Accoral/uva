#include <stdio.h>
int main ( ) {
	int n, m, i, node[10], count = 1, sum;
	char leaf[1<<8], s[10];
	while ( scanf ( "%d", &n ) != EOF && n ) {
		printf ( "S-Tree #%d:\n", count++ );
		for ( i = 0; i < n; ++i ) {
			scanf ( "%s", s );
			sscanf ( s, "%*c%d", node + i );
		}
		//for ( i = 0; i < n; ++i ) printf ( "node[%d]=%d ",i,node[i] ); printf ( "\n" );
		getchar ( );
		int len = 1 << n;
		for ( i = 0; i < len; ++i ) scanf ( "%c", leaf + i );

		scanf ( "%d", &m );
		while ( m-- ) {
			scanf ( "%s", s );
			sum = 1;
			for ( i = 0; i < n; ++i ) {
				int tmp = s[node[i]-1] - '0';
				if ( tmp ) sum = sum * 2 + 1;
				else sum *= 2;
				//printf ("i=%d,sum=%d, len=%d\n",i,sum,len );
			}
			printf ( "%c", leaf[sum-len] );
		}
		printf ( "\n\n" );
	}
}
