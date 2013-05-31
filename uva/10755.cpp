/*************************************************************************
    > File Name: 10755.cpp
    > Author: AC_coral
    > Mail: 313221234@qq.com 
    > Created Time: 2013年05月23日 星期四 14时40分47秒
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
int A, B, C;
long long a[20][20][20];
long long max1D ( long long x[] ) {
	long long ans = -INF -1;
	long long s = 0;
	for ( int i = 0; i < C; ++i ) {
		if ( s >= 0 ) s += x[i];
		else s = x[i];
		ans = max ( ans, s );
	}
	return ans;
}
long long max2D ( long long x[][20] ) {
	long long ans = -INF - 1;
	long long s[20];
	for ( int i = 0; i < B; ++i ) {
		memset ( s, 0, sizeof(s) );
		for ( int j = i; j < B; ++j ) {
			for ( int k = 0; k < C; ++k ) s[k] += x[j][k];
			ans = max ( ans, max1D(s) );
			//printf ( "2Dans=%d\n", ans ); for ( int k = 0; k < C; ++k ) printf ( "%d ", s[k] ); printf ( "\n" );
		}
	}
	return ans;
}
long long max3D ( long long x[][20][20] ) {
	long long ans = -INF - 1;
	long long s[20][20];
	for ( int i = 0; i < A; ++i ) {
		memset ( s, 0, sizeof(s) );
		for ( int j = i; j < A; ++j ) {
			for ( int k = 0; k < B; ++k )
				for ( int l = 0; l < C; ++l ) s[k][l] += x[j][k][l];
			ans = max ( ans, max2D(s) );
			/*
			for ( int k = 0; k < B; ++k ) {
				for ( int l = 0; l < C; ++l ) printf ( "%d ", s[k][l] );
				printf ( "\n" );
			}
			printf ( "\nans=%d\n", ans );
			*/
		}
	}
	return ans;
}
int main()
{
	int T, first = 1, i, j, k;
	scanf ( "%d", &T );
	while ( T-- ) {
		if ( first ) first = 0;
		else printf ( "\n" );
		scanf ( "%d%d%d", &A, &B, &C );
		for ( i = 0; i < A; ++i )
			for ( j = 0; j < B; ++j )
				for ( k = 0; k < C; ++k ) scanf ( "%lld", &a[i][j][k] );
		printf ( "%lld\n", max3D(a) );
	}
    return 0;
}
