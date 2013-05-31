#include <stdio.h>
#include <string.h>
#include <map>
using namespace std;
const int MAXN = 10000 + 10;
char s[MAXN];
map < char, int > mymap;
int main ( ) {
	int cases, x, i, j, len, ans, n;
	char c;
	while ( scanf ( "%d", &cases ) != EOF ) {
		while ( cases-- ) {
			scanf ( "%d\n", &n );
			mymap.clear ( );
			for ( i = 0; i < n; ++i ) {
				scanf ( "%c %d\n", &c, &x );
				mymap[c] = x;
			}
			scanf ( "%d\n", &n );
			for ( ans = i = 0; i < n; ++i ) {
				fgets ( s, MAXN, stdin );
				//printf ( "s=%s\n", s );
				len = strlen ( s );
				for ( j = 0; j < len - 1; ++j ) ans += mymap[s[j]];
			}
			printf ( "%d.%d%d$\n", ans / 100, ans / 10 % 10, ans % 10 );
		}
	}
}
