/*************************************************************************
    > File Name: 837.cpp
    > Author: AC_coral
    > Mail: 313221234@qq.com 
    > Created Time: 2013年05月24日 星期五 19时31分02秒
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
const int MUL = 10;
const int MAXN = 1000000;
double a[MAXN];
int main()
{
	int T, i, j, n, cnt, first = 1;
	double x1, y1, x2, y2, r, left, right;
	scanf ( "%d", &T );
	while ( T-- ) {
		if ( first ) first = 0;
		else printf ( "\n" );
		scanf ( "%d", &n );
		for ( i = 0; i < MAXN; ++i ) a[i] = 1;
		left = 1e10; right = 0;
		for ( i = 0; i < n; ++i ) {
			scanf ( "%lf%lf%lf%lf%lf", &x1, &y1, &x2, &y2, &r );
			if ( x1 > x2 ) swap ( x1, x2 );
			x1 *= MUL; x2 *= MUL;
			left = min ( left, x1 ); right = max ( right, x2 );
			for ( j = x1; j < x2; ++j ) a[j] *= r;
		}
		//printf ( "lf=%lf\tri=%lf\n", left, right );
		for ( cnt = 0, i = left; i <= right; ++i ) if ( a[i] != a[i+1] ) ++cnt;
		printf ( "%d\n", 2+cnt );
		printf ( "-inf %.3lf %.3lf\n", (double)left/MUL, 1. );
		for ( i = left; i <= right; ++i ) if ( a[i] != a[i+1] ) {
			printf ( "%.3lf %.3lf %.3lf\n", (double)left/MUL, (double)(i+1)/MUL, a[i] );
			left = i+1;
		}
		printf ( "%.3lf +inf %.3lf\n", (double)right/MUL, 1. );
	}
    return 0;
}
