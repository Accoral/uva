/*************************************************************************
    > File Name: 108.cpp
    > Author: AC_coral
    > Mail: 313221234@qq.com 
    > Created Time: 2013年05月23日 星期四 09时55分57秒
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
const int MAXN = 128;
const int INF = 0x7fffffff;
int a[MAXN][MAXN], n;
int max1D ( int x[] ) {
	int ans = -INF;
	int s = 0;
	for ( int i = 0; i < n; ++i ) {
		if ( s >= 0 ) s += x[i];
		else s = x[i];
		ans = max ( ans, s );
	}
	return ans;
}
int max2D ( int x[][MAXN] ) {
	int ans = -INF;
	int s[MAXN];
	for ( int i = 0; i < n; ++i ) {
		memset ( s, 0, sizeof(s) );
		for ( int j = i; j < n; ++j ) {
			for ( int k = 0; k < n; ++k ) s[k] += x[j][k];
			ans = max ( ans, max1D(s) );
		}
	}
	return ans;
}
int main()
{
	int i, j;
	while ( scanf ( "%d", &n ) != EOF ) {
		for ( i = 0; i < n; ++i ) for ( j = 0; j < n; ++j ) scanf ( "%d", &a[i][j] );
		printf ( "%d\n", max2D(a) );
	}
    return 0;
}
