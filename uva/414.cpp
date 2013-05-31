#include <stdio.h>
int n, i, max_n, count, sum;
char s[29];
int main ( ) {
while ( scanf ( "%d", &n ) == 1 && n ) {
		getchar ( );
		sum = max_n = 0;
		for ( int j = 0; j < n; ++j ) {
			fgets ( s, sizeof ( s ), stdin );
			for ( count = i = 0; i < 25; ++i )
				if ( s[i] == 'X' ) count++;
			if ( max_n < count ) max_n = count;
			sum += count;
		}
		printf ( "%d\n", n*max_n - sum );
	}
}
