#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
using namespace std;
//string s[205];
vector < string > s;
void dfs ( int x, int begin, int end ) {
	//printf ( "x=%d begin=%d end=%d\n", x, begin, end );
	int i;
	printf ( "(" );
	for ( i = begin; i < end && i < s[x].length ( ); ++i) {
		if ( s[x][i] == ' ' ) continue;
		printf ( "%c", s[x][i] );
		if ( x+1<s.size()&&s[x+1][i] == '|' ) {
			int b, e, pos;
			for ( pos = i; pos > 0 && s[x+2][pos] == '-'; --pos );
			b = pos;
			for ( pos = i; pos < s[x+2].length ( ) && s[x+2][pos] == '-'; ++pos );
			e = pos;
			dfs ( x + 3, b, e );
		}
		else printf ( "()" );
	}
	printf ( ")" );
}
int main ( ) {
	int T;
	string str;
	while ( scanf ( "%d", &T ) != EOF ) {
		getchar ( );
		while ( T-- ) {
			s.clear ( );
			while ( getline ( cin, str ) ) {
				if ( str == "#" ) break;
				s.push_back ( str );
			}
			//for ( int i = 0; i < s.size ( ); ++i ) cout << s[i] << endl;
			if ( s.empty ( ) ) printf ( "()" );
			else dfs ( 0, 0, s[0].length ( ) );
			printf ( "\n" );
		}
	}
}
