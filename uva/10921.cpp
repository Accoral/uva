/*************************************************************************
    > File Name: 10921.cpp
    > Author: AC_coral❤
    > Mail: 313221234@qq.com 
    > Created Time: 2013年06月02日 星期日 22时33分25秒
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
map < char, char > mymap;
void prepare ( ) {
	mymap['A'] = mymap['B'] = mymap['C'] = '2';
	mymap['D'] = mymap['E'] = mymap['F'] = '3';
	mymap['G'] = mymap['H'] = mymap['I'] = '4';
	mymap['J'] = mymap['K'] = mymap['L'] = '5';
	mymap['M'] = mymap['N'] = mymap['O'] = '6';
	mymap['P'] = mymap['Q'] = mymap['R'] = mymap['S'] = '7';
	mymap['T'] = mymap['U'] = mymap['V'] = '8';
	mymap['W'] = mymap['X'] = mymap['Y'] = mymap['Z'] = '9';
	mymap['-'] = '-';
}
string s;
void print ( char x ) {
	if ( isdigit ( x ) ) cout << x;
	else cout << mymap[x];
}
int main()
{
	prepare ( );
	int i, len;
	while ( cin >> s ) {
		for_each ( s.begin(), s.end(), print );
		puts ( "" );
	}
    return 0;
}
