#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
int flag[2001];
bool mycmp ( int x, int y ) { return x > y; }
int func ( int n ) {
	char str[10];
	int a, b;
	sprintf ( str, "%d", n );
	sort ( str, str + strlen ( str ) );
	sscanf ( str, "%d", &a );
	sort ( str, str + strlen ( str ), mycmp );
	sscanf ( str, "%d", &b );
	printf ( "%d - %d = %d\n", b, a, b - a );
	return b - a;
}
int main ( ) {
	int n;
	while ( scanf ( "%d", &n ) != EOF && n ) {
		printf ( "Original number was %d\n", n );
		memset ( flag, 0, sizeof ( flag ) );
		int count = 1; flag[0] = n;
		bool found = false;
		while ( 1 ) {
			flag[count] = func ( flag[count - 1] );
			for ( int i = 0; i < count; ++i )
				if ( flag[i] == flag[count] ) {
					found = true;
					break;
				}
			if ( found ) break;
			count++;
		}
		printf ( "Chain length %d\n\n", count );
	}
}
