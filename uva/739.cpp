/*************************************************************************
    > File Name: 739.cpp
    > Author: AC_coral❤
    > Mail: 313221234@qq.com 
    > Created Time: 2013年06月04日 星期二 18时00分42秒
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
map < char, int > mymap;
void prepare ( ) {
	mymap['B'] = mymap['P'] = mymap['F'] = mymap['V'] = 1;
	mymap['C'] = mymap['S'] = mymap['K'] = mymap['G'] = mymap['J'] = mymap['Q'] = mymap['X'] = mymap['Z'] = 2;
	mymap['D'] = mymap['T'] = 3;
	mymap['L'] = 4;
	mymap['M'] = mymap['N'] = 5;
	mymap['R'] = 6;
}
int main()
{
	prepare ( );
	char str[25];
	string s;
	int len, i, pre, now;
	printf ( "         NAME                     SOUNDEX CODE\n" );
	while ( scanf ( "%s", str ) != EOF ) {
		len = strlen ( str );
		s.clear ( ); s += str[0], pre = 0;
		if ( mymap[str[0]] ) pre = mymap[str[0]];
		else pre = 0;
		for ( i = 1; i < len; ++i ) {
			now = mymap[str[i]];
			if ( now && pre != now ) s += now+'0';
			pre = now;
		}
		s += "000";
		printf ( "         %-25s", str );
		for ( i = 0; i < 4; ++i ) printf ( "%c", s[i] );
		printf ( "\n" );
	}
	printf ( "                   END OF OUTPUT\n" );
    return 0;
}
