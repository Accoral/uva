#include <stdio.h>
#include <vector>
#include <string.h>
#include <string>
#include <iostream>
using namespace std;
const int MAXN = 20000;
char s[MAXN];
vector < int > v;
vector < string > u;
int main ( ) {
	int cases, tmp, i, n, first;
	string x;
	while ( scanf ( "%d", &cases ) != EOF ) {
		getchar ( );
		first = 0;
		while ( cases-- ) {
			if ( first ) printf ( "\n" );
			else first = 1;
			getchar ( );
			v.clear ( ); u.clear ( );
			fgets ( s, MAXN, stdin );
			//printf ( "s=%s\n", s );
			char *pch;
			pch = strtok ( s, " " );
			while ( pch != NULL ) {
				sscanf ( pch, "%d", &tmp );
				v.push_back ( tmp );
				pch = strtok ( NULL, " " );
			}
			//for ( i = 0; i < v.size ( ); ++i ) printf ( "%d ", v[i] ); printf ( "\n" );
			n = v.size ( );
			for ( i = 0; i < n; ++i ) {
				cin >> x;
				u.push_back ( x );
			}
			string ans[n];
			for ( i = 0; i < n; ++i ) ans[v[i]-1] = u[i];
			for ( i = 0; i < n; ++i ) printf ( "%s\n", ans[i].c_str ( ) );
			getchar ( );
		}
	}
}
