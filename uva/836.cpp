/*************************************************************************
    > File Name: 836.cpp
    > Author: AC_coral
    > Mail: 313221234@qq.com 
    > Created Time: 2013年05月23日 星期四 10时43分29秒
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
int a[30][30], len;
int max1D ( int x[] ) {
	int ans = 0;
	int s = 0;
	for ( int i = 0; i < len; ++i ) {
		if ( x[i] ) {
			s += x[i]-1;
			ans = max ( ans, s );
		}
		else s = 0;
	}
	return ans;
}
int max2D ( int x[][30] ) {
	int ans = 0;
	int s[30];
	for ( int i = 0; i < len; ++i ) {
		for ( int k = 0; k < len; ++k ) s[k] = 1;
		for ( int j = i; j < len; ++j ) {
			for ( int k = 0; k < len; ++k ) {
				if ( x[j][k] && s[k] ) s[k] += x[j][k];
				else s[k] = 0;
			}
			ans = max ( ans, max1D(s) );
			//for ( int k = 0; k < len; ++k ) printf ( "%d ", s[k] ); printf ( "\n" );
			//printf ( "j=%d ans=%d\n", j, ans );
		}
	}
	return ans;
}
int main()
{
	int T, first = 1;
	char str[30];
	scanf ( "%d", &T );
	while ( T-- ) {
		if ( first ) first = 0;
		else printf ( "\n" );
		len = 30;
		for ( int i = 0; i < len; ++i ) {
			scanf ( "%s", str );
			for ( int j = 0; j < len; ++j ) a[i][j] = str[j] - '0';
			len = strlen ( str );
		}
		printf ( "%d\n", max2D ( a ) );
	}
    return 0;
}
