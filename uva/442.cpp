#include <stdio.h>
#include <string.h>
#include <stack>
#include <map>
using namespace std;
int main ( ) {
	int n, x, y, len, i, ans, flag;
	char c, s[5000];
	while ( scanf ( "%d", &n ) != EOF ) {
		map < int, pair < int, int > > mymap;
		pair < int, int > p1, p2;
		for ( i = 0; i < n; ++i ) {
			getchar ( );
			scanf ( "%c%d%d", &c, &x, &y );
			//printf ( "%c %d %d\n", c, x, y );
			mymap[c] = make_pair ( x, y );
		}
		while ( scanf ( "%s", s ) != EOF ) {
			//printf ( "s=%s\n", s );
			len = strlen ( s ), ans = 0;
			stack < pair < int, int > > mystack;
			flag = 1;
			for ( i = 0; flag && i < len; ++i ) {
				if ( s[i] == '(' ) continue;
				else if ( s[i] == ')' ) {
					p2 = mystack.top ( );
					mystack.pop ( );
					p1 = mystack.top ( );
					mystack.pop ( );
					if ( p1.second != p2.first ) {
						printf ( "error\n" );
						flag = 0;
						break;
					}
					else {
						ans += p1.first * p1.second * p2.second;
						mystack.push ( make_pair ( p1.first, p2.second ) );
					}
				}
				else mystack.push ( mymap[s[i]] );
			}
			if ( flag ) printf ( "%d\n", ans );
		}
	}
}
