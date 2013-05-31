#include <iostream>
#include <stdio.h>
#include <string>
#include <map>
using namespace std;
map < string, int > mymap;
map < string, int > :: iterator it;
string change ( string s ) {
	string ret;
	for ( int i = 0; s[i]; ++i ) {
		if ( s[i] == '-' ) continue;
		if ( isdigit ( s[i] ) ) ret += s[i];
		else switch ( s[i] ) {
			case 'A':
			case 'B':
			case 'C': ret += '2';
					  break;
			case 'D':
			case 'E':
			case 'F': ret += '3';
					  break;
			case 'G':
			case 'H':
			case 'I': ret += '4';
					  break;
			case 'J':
			case 'K':
			case 'L': ret += '5';
					  break;
			case 'M':
			case 'N':
			case 'O': ret += '6';
					  break;
			case 'P':
			case 'R':
			case 'S': ret += '7';
					  break;
			case 'T':
			case 'U':
			case 'V': ret += '8';
					  break;
			case 'W':
			case 'X':
			case 'Y': ret += '9';
					  break;
		}
	}
	return ret;
}
int main ( ) {
	int t, n;
	bool first = 1;
	string s;
	while ( scanf ( "%d", &t ) != EOF ) {
		while ( t-- ) {
			if ( first ) first = 0;
			else printf ( "\n" );
			scanf ( "%d", &n );
			mymap.clear ( );
			while ( n-- ) {
				cin >> s;
				//printf ( "change = %s\n", change ( s ).c_str ( ) );
				++mymap[ change ( s ) ];
			}
			bool flag = 1;
			for ( it = mymap.begin ( ); it != mymap.end ( ); ++it )
				if ( it -> second > 1 ) {
					flag = 0;
					for ( int i = 0; i < 3; ++i ) cout << it -> first[i];
					cout << '-';
					for ( int i = 3; i < 7; ++i ) cout << it -> first[i]; 
					cout << ' ' << it -> second << "\n";
				}
			if ( flag ) cout << "No duplicates.\n";
		}
	}
}
