#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;
map < string, int > mymap;
string s[1100], tmp;
vector < string > ans;
int main ( ) {
	int n = 0;
	mymap.clear ( ), ans.clear ( );
	for ( n = 0; ; ++n ) {
		cin >> s[n];
		if ( s[n] == "#" ) break;
		tmp = s[n];
		for ( int i = 0; tmp[i]; ++i ) tmp[i] = tolower ( tmp[i] );
		sort ( tmp.begin ( ), tmp.end ( ) );
		//cout << s[n] << "	" << tmp << "*\n";
		++mymap[tmp];
	}
	for ( int i = 0; i < n; ++i ) {
		tmp = s[i];
		for ( int j = 0; tmp[j]; ++j ) tmp[j] = tolower ( tmp[j] );
		sort ( tmp.begin ( ), tmp.end ( ) );
		//cout << "tmp=" << s[i] << ' ' << mymap[tmp] << endl;
		if ( mymap[tmp] == 1 ) ans.push_back ( s[i] );
	}
	sort ( ans.begin ( ), ans.end ( ) );
	for ( int i = 0; i < ans.size ( ); ++i ) cout << ans[i] << "\n";
}
