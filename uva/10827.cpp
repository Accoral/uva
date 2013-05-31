/*************************************************************************
    > File Name: 10827.cpp
    > Author: AC_coral
    > Mail: 313221234@qq.com 
    > Created Time: 2013年05月23日 星期四 12时56分48秒
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
int n, a[160][160];
int max_sum ( int x[], int from ) {
	int ans = -INF;
	int s = 0;
	for ( int i = 0; i < n/2 && i + from < n; ++i ) {
		if ( s >= 0 ) s += x[i+from];
		else s = x[i+from];
		ans = max ( ans, s );
		//printf ( "%d ", x[i+from] );
	}
	//printf ( "\n" );
	return ans;
}
int max1D ( int x[] ) {
	int ans = -INF;
	for ( int i = 0; i < n; ++i ) {
		ans = max ( ans, max_sum(x,i) );
	}
	return ans;
}
int max2D ( int x[][160] ) {
	int ans = -INF;
	int s[160], cnt;
	for ( int i = 0; i < n; ++i ) {
		memset ( s, 0, sizeof(s) );
		cnt = 0;
		for ( int j = i; j < n; ++j ) {
			for ( int k = 0; k < n; ++k ) s[k] += a[j][k];
			ans = max ( ans, max1D(s) );
			//for ( int k = 0; k < n; ++k ) printf ( "%d ", s[k] ); printf ( "\n" ); printf ( "ans = %d\n", ans );
			++cnt;
			if ( cnt == ( n >> 1 ) ) { cnt = 0; break; }
		}
	}
	return ans;
}
int main()
{
	int T, i, j;
	scanf ( "%d", &T );
	while ( T-- ) {
		scanf ( "%d", &n );
		for ( i = 0; i < n; ++i ) for ( j = 0; j < n; ++j ) scanf ( "%d", &a[i][j] );
		for ( i = 0; i < n; ++i ) for ( j = n; j < 2*n; ++j ) a[i][j] = a[i][j-n];
		for ( i = n; i < 2*n; ++i ) for ( j = 0; j < 2*n; ++j ) a[i][j] = a[i-n][j];
		n <<= 1;
		/*
		for ( i = 0; i < n; ++i ) {
			for ( j = 0; j < n; ++j ) printf ( "%d\t", a[i][j] );
			printf ( "\n" );
		}*/
		printf ( "%d\n", max2D(a) );
	}
    return 0;
}
