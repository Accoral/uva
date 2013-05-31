/*************************************************************************
    > File Name: 837_.cpp
    > Author: AC_coral
    > Mail: 313221234@qq.com 
    > Created Time: 2013年05月24日 星期五 20时42分21秒
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
struct Point {
	int x;
	double r;
	bool operator < ( const Point p ) const {
		return abs(x) < abs(p.x);
	}
};
Point pt[10000];
int main()
{
	int T, first = 1, n, i;
	double d_x1, d_x2, y1, y2, r;
	int x1, x2;
	scanf ( "%d", &T );
	while ( T-- ) {
		if ( first ) first = 0;
		else printf ( "\n" );
		scanf ( "%d", &n );
		for ( i = 0; i < n; ++i ) {
			scanf ( "%lf%lf%lf%lf%lf", &d_x1, &y1, &d_x2, &y2, &r );
			x1 = d_x1 * MUL; x2 = d_x2 * MUL;
			if ( x1 > x2 ) swap ( x1, x2 );
			pt[i].x = x1; pt[i].r = r;
			pt[i+n].x = -x2; pt[i+n].r = r;
		}
		sort ( pt, pt + 2*n );
		double e = 1;
		int now = pt[0].x;
		printf ( "%d\n", 2*n+1 );
		printf ( "-inf %.3lf %.3lf\n", (double)now/MUL, e );
		for ( i = 0; i < 2*n; ++i ) {
			if ( now != pt[i].x ) printf ( "%.3lf %.3lf %.3lf\n", (double)now/MUL, (double)abs(pt[i].x)/MUL, e );
			if ( pt[i].x >= 0 ) e *= pt[i].r;
			else e /= pt[i].r;
			now = abs(pt[i].x);
			//printf ( "pt[%d].x=%d	e=%.3lf\n", i, pt[i].x/10, e );
		}
		printf ( "%.3lf +inf %.3lf\n", (double)now/MUL, e );
	}
    return 0;
}
