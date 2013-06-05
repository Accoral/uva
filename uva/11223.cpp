/*************************************************************************
    > File Name: 11223.cpp
    > Author: AC_coral❤
    > Mail: 313221234@qq.com 
    > Created Time: 2013年06月05日 星期三 16时19分13秒
 ************************************************************************/

#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <climits>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <map>
#include <set>

using namespace std;
typedef unsigned int u32;
typedef long long i64;
typedef unsigned long long u64;
typedef vector<int> IV;
typedef vector<bool> BV;
typedef pair<int,int> II;
typedef vector<II> IIV;
#define For(t,v,c) for(t::const_iterator v=c.begin(); v!=c.end(); ++v)
const int INF = 0x7FFFFFFF;
const int MAXN = 2013;
char str[MAXN];
map < string, char > mymap;
void prepare ( ) {
	mymap[".-"] = 'A';
	mymap["-..."] = 'B';
	mymap["-.-."] = 'C';
	mymap["-.."] = 'D';
	mymap["."] = 'E';
	mymap["..-."] = 'F';
	mymap["--."] = 'G';
	mymap["...."] = 'H';
	mymap[".."] = 'I';
	mymap[".---"] = 'J';
	mymap["-.-"] = 'K';
	mymap[".-.."] = 'L';
	mymap["--"] = 'M';
	mymap["-."] = 'N';
	mymap["---"] = 'O';
	mymap[".--."] = 'P';
	mymap["--.-"] = 'Q';
	mymap[".-."] = 'R';
	mymap["..."] = 'S';
	mymap["-"] = 'T';
	mymap["..-"] = 'U';
	mymap["...-"] = 'V';
	mymap[".--"] = 'W';
	mymap["-..-"] = 'X';
	mymap["-.--"] = 'Y';
	mymap["--.."] = 'Z';
	mymap["-----"] = '0';
	mymap[".----"] = '1';
	mymap["..---"] = '2';
	mymap["...--"] = '3';
	mymap["....-"] = '4';
	mymap["....."] = '5';
	mymap["-...."] = '6';
	mymap["--..."] = '7';
	mymap["---.."] = '8';
	mymap["----."] = '9';
	mymap[".-.-.-"] = '.';
	mymap["--..--"] = ',';
	mymap["..--.."] = '?';
	mymap[".----."] = '\'';
	mymap["-.-.--"] = '!';
	mymap["-..-."] = '/';
	mymap["-.--."] = '(';
	mymap["-.--.-"] = ')';
	mymap[".-..."] = '&';
	mymap["---..."] = ':';
	mymap["-.-.-."] = ';';
	mymap["-...-"] = '=';
	mymap[".-.-."] = '+';
	mymap["-....-"] = '-';
	mymap["..--.-"] = '_';
	mymap[".-..-."] = '"';
	mymap[".--.-."] = '@';
}
int main()
{
	prepare ( );
	int T, i, len, ncase = 1, first = 1;
	string  s;
	scanf ( "%d", &T );
	fgets ( str, MAXN, stdin );
	while ( T-- ) {
		if ( first ) first = 0;
		else puts ( "" );
		printf ( "Message #%d\n", ncase++ );
		fgets ( str, MAXN, stdin );
		//puts ( str );
		len = strlen ( str ) - 1;
		s.clear ( );
		for ( i = 0; i < len; ) {
			if ( str[i] == ' ' && str[i+1] == ' ' ) {
				if ( s.empty() ) printf ( " " );
				else printf ( "%c ", mymap[s] ), s.clear();
				i += 2;
			}
			else if ( str[i] == ' ' ) {
				if ( s.empty() ) ++i;
				else printf ( "%c", mymap[s] ), s.clear(), ++i;
			}
			else s += str[i], ++i;
		}
		if ( !s.empty() ) printf ( "%c\n", mymap[s] );
		else printf ( "\n" );
	}
    return 0;
}
