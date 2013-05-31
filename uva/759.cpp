/*************************************************************************
    > File Name: 759.cpp
    > Author: AC_coral
    > Mail: 313221234@qq.com 
    > Created Time: 2013年05月25日 星期六 21时19分10秒
 ************************************************************************/

#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <climits>
#include <sstream>
#include <fstream>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <map>
#include <set>

using namespace std;
const int INF = 0x7FFFFFFF;
map < string, int > mymap;
vector < int > v;
const int val[] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1, };
const char *s[] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I", };
string n2r ( int x ) {
	string res = "";
	int i = 0;
	while ( x ) {
		while ( x >= val[i] ) {
			x -= val[i];
			res += s[i];
		}
		++i;
	}
	//cout << res << endl;
	return res;
}
int main()
{
	for ( int i = 1; i < 4000; ++i ) mymap[n2r(i)] = i;
	string s;
	while ( getline ( cin, s ) ) {
		if ( mymap.count ( s ) ) printf ( "%d\n", mymap[s] );
		else printf ( "This is not a valid number\n" );
	}
    return 0;
}
