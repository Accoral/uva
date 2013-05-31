#include <math.h>
#include <stdio.h>
int main ( ) {
	int n;
	while ( scanf ( "%d", &n ) != EOF ) {
		int k =  floor ( ( sqrt ( 1 + 8*n ) - 1 ) / 2 - 1E-9 ) + 1;
		int s = k*(k+1)/2;
		if ( k % 2 == 0 ) printf ( "TERM %d IS %d/%d\n", n, k-s+n, s-n+1 );
		else printf ( "TERM %d IS %d/%d\n", n, s-n+1, k-s+n );
	}
}
