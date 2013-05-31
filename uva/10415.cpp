/*************************************************************************
    > File Name: 10415.cpp
    > Author: AC_coral
    > Mail: 313221234@qq.com 
    > Created Time: 2013年05月26日 星期日 10时23分08秒
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
map < char, vector <int> > mymap;
const int low[] = { 2, 3, 4, 7, 8, 9, 10, };
const char low_char[] = { 'b', 'a', 'g', 'f', 'e', 'd', 'c', };
const int up[] = { 2, 3, 4, 7, 8, 9, };
const char up_char[] = { 'B', 'A', 'G', 'F', 'E', 'D', };
void init ( ) {
	vector < int > v;
	for ( int i = 0; i < 7; ++i ) {
		v.push_back ( low[i] );
		mymap[low_char[i]] = v;
	}
	v.clear ( ); v.push_back ( 1 );
	for ( int i = 0; i <6; ++i ) {
		v.push_back ( up[i] );
		mymap[up_char[i]] = v;
	}
	v.clear ( ); v.push_back ( 3 );
	mymap['C'] = v;
}
int main()
{
	init ( );
	//for ( int i = 0; i <mymap['C'].size(); ++i ) printf ( "%d ", mymap['C'][i] );
	int T, i, j, len, ans[11], button[11];
	char s[256];
	scanf ( "%d", &T );
	fgets ( s, 256, stdin );
	while ( T-- ) {
		fgets ( s, 256, stdin );
		//printf ( "s=%s", s );
		len = strlen ( s ) - 1;
		memset ( ans, 0, sizeof(ans) );
		memset ( button, 0, sizeof(button) );
		for ( i = 0; i < len; ++i ) {
			for ( j = 1; j <= 10; ++j ) {
				if ( !binary_search ( mymap[s[i]].begin(), mymap[s[i]].end(), j ) ) button[j] = 0;
				else {
					if ( button[j] == 0 ) {
						button[j] = 1;
						++ans[j];
					}
				}
			}
		}
		for ( i = 1; i < 10; ++i ) printf ( "%d ", ans[i] ); printf ( "%d\n", ans[10] );
	}
    return 0;
}
