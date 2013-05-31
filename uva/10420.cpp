#include <stdio.h>
#include <iostream>
#include <string>
#include <map>
#include <set>
using namespace std;
string country, s, name;
map < string, set < string > > mymap;
map < string, set < string > > :: iterator it;
int main ( ) {
	int n, i;
	while ( cin >> n ) {
		getchar ( );
		mymap.clear ( );
		while ( n-- ) {
			getline ( cin, s );
			country.clear ( ), name.clear ( );
			for ( i = 0; s[i] != ' '; ++i ) country += s[i];
			for ( ; s[i]; ++i ) name += s[i];
			//cout << country << '	' << name << endl;
			mymap[country].insert ( name );
		}
		for ( it = mymap.begin ( ); it != mymap.end ( ); ++it )
			cout << it -> first << ' ' << it -> second.size ( ) << "\n";

	}
}
