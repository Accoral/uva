#include <iostream>
#include <string>
using namespace std;
string s;
int main ( ) {
	while ( getline ( cin, s ) ) {
		int len = s.length ( ), ans = 0, i;
		bool have_count = false;
		for ( i = 0; i < len; ++i ) {
			if ( isalpha ( s[i] ) ) {
				if ( !have_count ) ++ans, have_count = true;
			}
			else have_count = false;
		}
		cout << ans << "\n";
	}
}
