#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
using namespace std;
const int MAXN = 1000;
struct bign {
	int len, s[MAXN];
	bign ( ) {
		memset ( s, 0, sizeof ( s ) );
		len = 1;
	}
	bign operator = ( const char *num ) {
		len = strlen ( num );
		for ( int i = 0; i < len; ++i ) s[i] = num[len-i-1] - '0';
		return *this;
	}
	bign ( const char *num ) { *this = num; }
	bign operator = ( int num ) {
		char s[MAXN];
		sprintf ( s, "%d", num );
		*this = s;
		return *this;
	}
	bign ( int num ) { *this = num; }
	string str ( ) const {
		string res = "";
		for ( int i = 0; i < len; ++i ) res = ( char ) ( s[i] + '0' ) + res;
		if ( res == "" ) res = "0";
		return res;
	}
	bign operator + ( const bign &b ) const {
		bign c;
		c.len = 0;
		for ( int i = 0, g = 0; g || i < max ( len, b.len ); ++i ) {
			int x = g;
			if ( i < len ) x += s[i];
			if ( i < b.len ) x += b.s[i];
			c.s[c.len++] = x % 10;
			g = x / 10;
		}
		return c;
	}
	bign operator += ( const bign &b ) {
		*this = *this + b;
		return *this;
	}
};
istream& operator >> ( istream &in, bign &x ) {
	string s;
	in >> s;
	x = s.c_str ( );
	return in;
}
ostream& operator << ( ostream &out, const bign &x ) {
	out << x.str ( );
	return out;
}
int main ( ) {
	bign ans = 0;
	string s;
	while ( cin >> s ) {
		if ( s == "0" ) break;
		bign n = s.c_str ( );
		ans += n;
	}
	cout << ans << "\n";
}
