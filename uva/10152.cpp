#include <stdio.h>
#include <stack>
#include <iostream>
#include <string>
using namespace std;
string s;
int main ( ) {
	int n, cases, i;
	while ( scanf ( "%d", &cases ) != EOF ) {
		while ( cases-- ) {
			scanf ( "%d", &n );
			getchar ( );
			stack < string > s1, s2;
			for ( i = 0; i < n; ++i ) {
				getline ( cin, s );
				s1.push ( s );
			}
			for ( i = 0; i < n; ++i ) {
				getline ( cin, s );
				s2.push ( s );
			}
			while ( !s1.empty ( ) ) {
				if ( s1.top ( ) == s2.top ( ) ) {
					s1.pop ( ); s2.pop ( );
				}
				else s1.pop ( );
			}
			while ( !s2.empty ( ) ) {
				cout << s2.top ( ) << "\n";
				s2.pop ( );
			}
			printf ( "\n" );
		}
	}
}
