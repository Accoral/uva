#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
vector < char > v;
int main ( ) {
	int n, i;
	char s[15];
	while ( scanf ( "%d", &n ) != EOF ) {
		while ( n-- ) {
			scanf ( "%s", s );
			v.clear ( );
			for ( i = 0; i < strlen ( s ); ++i ) v.push_back ( s[i] );
			sort ( v.begin ( ), v.end ( ) );
			do {
				for ( i = 0; i < v.size ( ); ++i ) printf ( "%c", v[i] );
				printf ( "\n" );
			} while ( next_permutation ( v.begin ( ), v.end ( ) ) );
			printf ( "\n" );
		}
	}
}
