/*************************************************************************
    > File Name: 10074.cpp
    > Author: AC_coral
    > Mail: 313221234@qq.com 
    > Created Time: 2013年05月23日 星期四 12时12分39秒
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
int a[128][128], m, n;
int max1D ( int x[] ) {
	int ans = 0;
	int s = 0;
	for ( int i = 0; i < n; ++i ) {
		if ( x[i] ) {
			s += x[i] - 1;
			ans = max ( ans, s );
		}
		else s = 0;
	}
	return ans;
}
int max2D ( int x[][128] ) {
	int ans = 0;
	int s[128];
	for ( int i = 0; i < m; ++i ) {
		for ( int k = 0; k < n; ++k ) s[k] = 1;
		for ( int j = i; j < m; ++j ) {
			for ( int k = 0; k < n; ++k ) {
				if ( !x[j][k] && s[k] ) ++s[k];
				else s[k] = 0;
			}
			ans = max ( ans, max1D(s) );
			//for ( int k = 0; k < n; ++k ) printf ( "%d ", s[k] ); printf ( "\n" );
		}
	}
	return ans;
}
int main()
{
	int i, j;
	while ( scanf ( "%d%d", &m, &n ) != EOF ) {
		if ( !m && !n ) break;
		for ( i = 0; i < m; ++i ) for ( j = 0; j < n; ++j ) scanf ( "%d", &a[i][j] );
		printf ( "%d\n", max2D ( a ) );
	}
    return 0;
}
