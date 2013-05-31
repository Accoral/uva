#include <iostream>
#include <string>
#include <string.h>
#include <math.h>
#include <stdio.h>
using namespace std;
const int MAXN = 2000;
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
	bign ( int num ) {
		*this = num;
	}
	bign operator = ( int num ) {
		char s[MAXN];
		sprintf ( s, "%d", num );
		*this = s;
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
ostream& operator << ( ostream &out, bign&x ) {
	out << x.str ( );
	return out;
}
int main ( ) {
	double R;
	int n;
	//cout << 0x7fffffff << endl;
	while ( cin >> R >> n ) {
		//cout << R << ' ' << n << endl;
		int count = 0;
		for ( count = 0; count < 4; ++count ) {
			if ( R > 999999 ) break;
			R *= 10;
		}
		//cout << "count="<<count<<" R="<<R << endl;
		bign r = floor ( R + 0.5 );
		//cout << "r=" << r << endl;
		bign ans = 1;
		for ( int i = 0; i < n; ++i ) ans *= r;
		//cout << ans << endl;
		//cout << ans.len <<"   " << ans.str()<< "\n";
		string result;
		int len = ans.len - count * n;
		if ( len < 0 ) {
			result += '.', len *= -1;
			while ( len-- ) result += '0';
			result += ans.str ( );
		}
		else {
			int i;
			for ( i = 0; i < len; ++i ) result += ans.str()[i];
			result += '.';
			for ( ; i < ans.len; ++i ) result += ans.str()[i];
		}
		string s;
		len = result.length ( );
		int i;
		for ( i = len- 1; i >= 0 && result[i] == '0'; --i );
		for ( ; i >= 0; --i ) s += result[i];
		len = s.length ( );
		for ( i = len -1; i >= 0; --i ) cout << s[i];
		cout << "\n";
	}
}
