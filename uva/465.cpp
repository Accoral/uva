#include <iostream>
#include <string>
#include <string.h>
#include <stdio.h>
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
		for ( int i = 0; i < len; ++i ) res = (char)(s[i]+'0') + res;
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
	void clean ( ) {
		while ( len > 1 && !s[len-1] ) len--;
	}
	bign operator * ( const bign &b ) const {
		bign c; c.len = len + b.len;
		for ( int i = 0; i < len; ++i )
			for ( int j = 0; j < b.len; ++j )
				c.s[i+j] += s[i] * b.s[j];
		for ( int i = 0; i < c.len; ++i )
			c.s[i+1] += c.s[i]/10, c.s[i] %= 10;
		c.clean ( );
		return c;
	}
	bool operator < ( const bign &b ) const {
		if ( len != b.len ) return len < b.len;
		for ( int i = len - 1; i >= 0; --i )
			if ( s[i] != b.s[i] ) return s[i] < b.s[i];
		return false;
	}
	bool operator > ( const bign &b ) const {
		return b < *this;
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
char s1[100000], s2[100000], op[10];
int main ( ) {
	bign max_n = 0x7fffffff;
	//cout << max_n << endl;
	string s, s1, s2, op;
	while ( getline ( cin, s ) ) {
		cout << s << "\n";
		int i, len = s.length ( );
		s1.clear ( ); s2.clear ( );
		for ( i = 0; i < len && s[i] == '0'; ++i );
		for ( ; i < len; ++i )
			if ( s[i] == ' '||s[i]=='+'||s[i]=='*' ) break;
			else s1 += s[i];
		for ( ; i < len; ++i )
			if ( s[i] == '+' ) {
				op = "+";
				break;
			}
			else if ( s[i] == '*' ) {
				op = "*";
				break;
			}
		for ( ++i; (s[i] == '0'||s[i] == ' ') && i <len; ++i );
		for ( ; i < len; ++i ) s2 += s[i];
		//cout << "s1="<<s1 <<endl;
		//cout << "s2=" << s2 << endl;
		bign n1 = s1.c_str ( );
		bign n2 = s2.c_str ( );
		bign ans;
		if ( op == "+" ) ans = n1 + n2;
		else ans = n1 * n2;
		//cout << n1 << ' ' << op << ' ' << n2 << "\n";
		//cout << n1 << op << n2 << ' ' << ans<< endl;
		if ( n1 > max_n ) cout << "first number too big\n";
		if ( n2 > max_n ) cout << "second number too big\n";
		if ( ans > max_n ) cout << "result too big\n";
	}
}
