/*************************************************************************
    > File Name: poj1151.cpp
    > Author: AC_coral
    > Mail: 313221234@qq.com 
    > Created Time: 2013年05月25日 星期六 11时02分37秒
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
struct {
	double x1, y1, x2, y2;
}rec[256];
vector < double > x;
vector < double > y;
vector < double > :: iterator it;
int flag[256][256];
int main()
{
	int n, i, j, k, t = 1;
	while ( scanf ( "%d", &n ) != EOF && n ) {
		printf ( "Test case #%d\n", t++ );
		x.clear ( ); y.clear ( );
		for ( i = 0; i < n; ++i) {
			scanf ( "%lf%lf%lf%lf", &rec[i].x1, &rec[i].y1, &rec[i].x2, &rec[i].y2 );
			x.push_back ( rec[i].x1 );
			x.push_back ( rec[i].x2 );
			y.push_back ( rec[i].y1 );
			y.push_back ( rec[i].y2 );
		}
		sort ( x.begin(), x.end() );
		it = unique ( x.begin(), x.end() );
		x.resize ( distance ( x.begin(), it ) );
		sort ( y.begin(), y.end() );
		it = unique ( y.begin(), y.end() );
		y.resize ( distance ( y.begin(), it ) );

		memset ( flag, 0, sizeof(flag) );
		for ( i = 0; i < n; ++i ) {
			for ( j = 0; j < x.size(); ++j ) {
				if ( x[j] >= rec[i].x2 ) break;
				for ( k = 0; k < y.size(); ++k ) {
					if ( y[k] >= rec[i].y2 ) break;
					if ( x[j] >= rec[i].x1 && y[k] >= rec[i].y1 )
						flag[j][k] = 1;
				}
			}
		}
		double ans = 0.;
		for ( j = 0; j < x.size(); ++j )
			for ( k = 0; k < y.size(); ++k )
				ans += flag[j][k]*(x[j+1]-x[j])*(y[k+1]-y[k]);
		printf ( "Total explored area: %.2lf\n\n", ans );
	}
    return 0;
}
