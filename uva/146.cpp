#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
int main ( ) {
	string s;
	while ( cin >> s ) {
		if ( s == "#" ) break;
		if ( next_permutation ( s.begin ( ), s.end ( ) ) ) cout << s << "\n";
		else cout << "No Successor\n";
	}
}
