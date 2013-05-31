#include <iostream>
#include <string>
#include <set>
using namespace std;
string s, str;
set < string > myset;
int main ( ) {
	while ( getline ( cin, s ) ) {
		//cout << s << endl;
		str.clear ( );
		for ( int i = 0; s[i]; ++i )
			if ( isalpha ( s[i] ) ) str += tolower ( s[i] );
			else {
				//cout << str << "\n";
				if ( !str.empty ( ) && myset.count ( str ) == 0 ) myset.insert ( str );
				str.clear ( );
			}
		if ( !str.empty ( ) && myset.count ( str ) == 0 ) myset.insert ( str );
	}
	for ( set < string > :: iterator it = myset.begin ( ); it != myset.end ( ); ++it ) if ( *it == "") cout << "NULL\n";else cout << *it << "\n";
}
