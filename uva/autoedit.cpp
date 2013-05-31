#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;
int n, pos;
string str1[10], str2[10], s, blankline;
int main ( ) {
	//freopen ( "autoedit.in", "r", stdin );
	//freopen ( "autoedit.out", "w", stdout );
	while ( cin >> n ) {
		if ( !n ) break;
		//getline ( cin, blankline );
		getchar ( );
		for ( int i = 0; i < n; ++i ) {
			getline ( cin, str1[i] );
			getline ( cin, str2[i] );
		}
		getline ( cin, s );
		//cout << s << endl;
		for ( int i = 0; i < n; ++i )
			while ( ( pos = s.find ( str1[i] , 0 ) ) != string::npos ) {
				s.replace ( pos, str1[i].length ( ), str2[i] );
				//cout << str1[i] << "=>" <<str2[i]<<"*"<< s << endl;
			}
		cout << s << endl;
	}
}
