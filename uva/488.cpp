#include <stdio.h>
void print ( int x ) {
	for ( int i = 1; i <= x; ++i ) {
		for ( int j = 0; j < i; ++j )
			printf ( "%d", i );
		printf ( "\n" );
	}
	for ( int i = x - 1; i > 0; --i ) {
		for ( int j = 0; j < i; ++j )
			printf ( "%d", i );
		printf ( "\n" );
	}
}
int main ( ) {
	int n, amplitude, frequency;
	bool flag;
	while ( scanf ( "%d", &n ) != EOF ) {
		flag = false;
		while ( n-- ) {
			scanf ( "%d%d", &amplitude, &frequency );
			while ( frequency -- ) {
				if ( flag ) printf ( "\n" );
				flag = true;
				print ( amplitude );
			}
		}
	}
}
