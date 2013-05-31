#include <iostream>
#include <string>
#include <set>
#include <map>
using namespace std;
set < string > set_ignore;
map < pair <string,int>, string > mymap;
map < pair <string,int>, string > :: iterator it;
int main ( ) {
	string ignore, title, word;
	int i, start, end, n = 0;
	while ( cin >> ignore ) {
		if ( ignore == "::" ) break;
		set_ignore.insert ( ignore );
	}
	getline ( cin, title );
	while ( getline ( cin, title ) ) {
		for ( i = 0; title[i]; ++i ) title[i] = tolower ( title[i] );
		//cout << "title=" << title << ":\n";
		end = 0;
		while ( end < title.length ( ) ) {
			start = end;
			word.clear ( );
			for ( ; end < title.length ( ) && title[end] != ' '; ++end ) word += title[end];
			if ( !word.empty() && set_ignore.count ( word ) == 0 ) {
				for ( int k = 0; word[k]; ++k ) word[k] = toupper ( word[k] );
				string tmp;
				for ( int k = 0; k < start; ++k ) tmp += title[k];
				tmp += word;
				for ( int k = end; title[k]; ++k ) tmp += title[k]; 
				mymap[make_pair ( word, n++ )] = tmp;
				//cout << "word=" << word << endl;
				//cout << "tmp=" <<tmp<< "\n";
			}
			++end;
		}
	}
	for ( it = mymap.begin ( ); it != mymap.end ( ); ++it ) cout<<it -> second << "\n";
}
