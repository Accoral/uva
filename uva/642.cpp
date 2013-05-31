#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
string word[105], sorted[105], s;
int main ( ) {
	int n = 0;
	while ( 1 ) {
		cin >> word[n];
		if ( word[n][0] == 'X' ) break;
		++n;
	}
	sort ( word, word + n );
	for ( int i = 0; i < n; ++i ) {
		sorted[i]=word[i];
		sort ( sorted[i].begin ( ), sorted[i].end ( ) );
	}
	while ( 1 ) {
		cin >> s;
		if ( s[0] == 'X' ) break;
		sort ( s.begin ( ), s.end ( ) );
		bool found = false;
		for ( int i = 0; i < n; ++i )
			if ( s == sorted[i] ) {
				found = true;
			   	cout << word[i] << "\n";
			}
		if ( !found ) cout << "NOT A VALID WORD\n";
		cout << "******\n";
	}
}
