#include <iostream>
#include <stdio.h>
#include <map>
#include <string>
using namespace std;
map < string, int > mymap;
string plus_one ( string s ) {
	int i, len = s.length ( );
	for ( i = len - 1; i >= 0; --i )
		if ( s[i] == '0' ) {
			s[i] = '1';
			break;
		}
		else {
			s[i] = '0';
			continue;
		}
	return s;
}
void init ( ) {
	int count = 0, flag;
	for ( int i = 1; i < 8; ++i ) {
		string s, tmp;
		for ( int j = 0; j < i; ++j ) s += '0';
		while ( 1 ) {
			flag = 1;
			for ( int j = 0; j < i; ++j ) if ( s[j] == '0' ) flag = 0;
			if ( flag ) break;
			mymap[s] = count++;
			//cout << s <<"	"<<mymap[s]<< endl;
			s = plus_one ( s );
		}
	}
}
int main ( ) {
	init ( );
	string s, str;
	int n, num, c, flag;
	while ( getline ( cin, s ) ) {
		//cout << "s=" << s << endl;
		while ( 1 ) {
			if ( ( c = getchar ( ) ) == '\n' ) continue;
			n = 0, num = ( c - '0' ) * 4;
			while ( n < 2 ) {
				if ( ( c = getchar ( ) ) == '\n' ) continue;
				//cout << "*c=" << (char)c << endl;
				num += ( c - '0' ) * ( 1 << ( 1 - n ) );
				//cout << "*num=" << num << endl;
				++n;
			}
			//cout << "	num=" << num << endl;
			if ( num == 0 ) break;
			while ( 1 ) {
				if ( ( c = getchar ( ) ) == '\n' ) continue;
				n = 0;
				str.clear ( );
				str += c;
				while ( n < num - 1 ) {
					if ( ( c = getchar ( ) ) == '\n' ) continue;
					str += c;
					++n;
				}
				flag = 1;
				for ( int i = 0; i < num; ++i ) if ( str[i] == '0' ) flag = 0;
				if ( flag ) break;
				//cout << "str=" << str << endl;
				cout << s[mymap[str]];
			}
			//++i;
		}
		cout << '\n';
		getchar ( );
	}
}
