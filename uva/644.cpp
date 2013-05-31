#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
using namespace std;
string s;
vector < string > v;
int i, j, size, flag, cases;
bool judge ( string s1, string s2 ) {//is perfix return 1
	int len1 = s1.length ( );
	int len2 = s2.length ( );
	for ( int i = 0; i < min ( len1, len2 ); ++i )
		if ( s1[i] != s2[i] ) return 0;
	return 1;
}
int main ( ) {
	flag = 0, cases = 1;
	while ( cin >> s ) {
		if ( s == "9" ) {
			//printf ( "flag = %d\n", flag );
			if ( flag ) printf ( "Set %d is not immediately decodable\n", cases++ );
			else printf ( "Set %d is immediately decodable\n", cases++ );
			flag = 0;
			v.clear ( );
			continue;
		}
		if ( !flag ) {
			size = v.size ( );
			for ( i = 0; i < size; ++i )
				if ( judge ( s, v[i] ) ) {
					flag = 1;
					break;
				}
			v.push_back ( s );
		}
	}
}
