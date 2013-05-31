#include <iostream>
#include <string.h>
#include <string>
using namespace std;
const int MAXN = 1000;
struct bign {
	int len, s[MAXN];
	bign ( ) {
		memset ( s, 0, sizeof ( s ) );
		len = 1;
	}
	bign ( const char *num ) {
		*this = num;
	}
	bign operator = ( const char *num ) {
		len = strlen ( num );
		for ( int i = 0; i < len; ++i ) s[i] = num[len-i-1]-'0';
		return *this;
	}
	string str ( ) const {
		string res = "";
		for ( int i = 0; i < len; ++i ) res = (char)(s[i]+'0')+res;
		if ( res == "" ) res = "0";
		return res;
	}
	void clean ( ) {
		while ( len > 1 && !s[len-1] ) len--;
	}
	bign operator * ( const bign &b ) const {
		bign c; c.len = len + b.len;
		for ( int i = 0; i < len; ++i )
			for ( int j = 0; j < b.len; ++j )
				c.s[i+j] += s[i] * b.s[j];
		for ( int i = 0; i < c.len; ++i )
			c.s[i+1] += c.s[i] / 10, c.s[i] %= 10;
		c.clean ( );
		return c;
	}
	bign operator *= ( const bign &b ) {
		*this = *this * b;
		return *this;
	}
};
istream& operator >> ( istream &in, bign &x ) {
	string s;
	in >> s;
	x = s.c_str ( );
	return in;
}
ostream& operator << ( ostream &out, bign &x ) {
	out << x.str ( );
	return out;
}
int main ( ) {
	bign x, y, ans;
	while ( cin >> x >> y ) {
		ans = x * y;
		cout << ans << "\n";
	}
}
