/*************************************************************************
    > File Name: 10667.cpp
    > Author: AC_coral
    > Mail: 313221234@qq.com 
    > Created Time: 2013年05月23日 星期四 12时32分37秒
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
int n, a[128][128];
int max1D ( int x[] ) {
	int ans = 0;
	int s = 0;
	for ( int i = 0; i < n; ++i ) {
		if ( x[i] ) s += x[i] - 1;
		else s = 0;
		ans = max ( ans, s );
	}
	return ans;
}
int max2D ( int x[][128] ) {
	int ans = 0;
	int s[128];
	for ( int i = 0; i < n; ++i ) {
		for ( int k = 0; k < n; ++k ) s[k] = 1;
		for ( int j = i; j < n; ++j ) {
			for ( int k = 0; k < n; ++k )
				if ( s[k] && !x[j][k] ) ++s[k];
				else s[k] = 0;
			ans = max ( ans, max1D(s) );
		}
	}
	return ans;
}
int main()
{
	int r1, c1, r2, c2, i, j, T, b;
	scanf ( "%d", &T );
	while ( T-- ) {
		scanf ( "%d%d", &n, &b );
		memset ( a, 0, sizeof(a) );
		while ( b-- ) {
			scanf ( "%d%d%d%d", &r1, &c1, &r2, &c2 );
			for ( i = r1-1; i < r2; ++i ) for ( j = c1-1; j < c2; ++j ) a[i][j] = 1;
		}
		/*
		for ( i = 0; i < n; ++i ) {
			for ( j = 0; j < n; ++j ) printf ( "%d ", a[i][j] );
			printf ( "\n" );
		}*/
		printf ( "%d\n", max2D(a) );
	}
    return 0;
}
