/*************************************************************************
    > File Name: 10613.cpp
    > Author: AC_coral
    > Mail: 313221234@qq.com 
    > Created Time: 2013年05月25日 星期六 08时51分06秒
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
	double x, y, r;
}circular[1010];
vector < int > x;
vector < int > y;
vector < int > :: iterator it;
int flag[1000000][1000000];
double dis ( int x1, int y1, int x2, int y2 ) {
	return sqrt ((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}
int main()
{
	int T, i, j, k, size, n, a, b;
	scanf ( "%d", &T );
	while ( T-- ) {
		scanf ( "%d%d", &size, &n );
		x.clear ( ); y.clear ( );
		for ( i = 0; i < n; ++i ) {
			scanf ( "%lf%lf%lf", &circular[i].x, &circular[i].y, &circular[i].r );
			x.push_back ( floor(circular[i].x - circular[i].r) );
			x.push_back ( ceil(circular[i].x + circular[i].r) );
			y.push_back ( floor(circular[i].y - circular[i].r) );
			y.push_back ( ceil(circular[i].y + circular[i].r) );
		}
		sort ( x.begin(), x.end() );
		it = unique ( x.begin(), x.end() );
		x.resize ( distance(x.begin(), it ) );

		sort ( y.begin(), y.end() );
		it = unique ( y.begin(), y.end() );
		y.resize ( distance(y.begin(), it ) );
		//for ( i = 0; i < x.size(); ++i ) printf ( "%d ", x[i] ); printf ( "\n" );
		//for ( i = 0; i < y.size(); ++i ) printf ( "%d ", y[i] ); printf ( "\n" );

		int ans = 0;
		for ( k = 0; k < n; ++k )
			for ( i = 0; i < x.size(); ++i )
				for ( j = 0; j < y.size(); ++j )
					for ( a = x[i]; a < x[i+1]; ++a )
						for ( b = y[j]; b < y[j+1]; ++b )
							if ( dis(a,b,circular[k].x,circular[k].y) < circular[k].r ||
									dis(a+1,b,circular[k].x,circular[k].y) < circular[k].r ||
									dis(a,b+1,circular[k].x,circular[k].y) < circular[k].r ||
									dis(a+1,b+1,circular[k].x,circular[k].y) < circular[k].r ) {
								//++ans;
								flag[a][b] = 1;
							}
		for ( i = 0; i < x.size(); ++i )
			for ( j = 0; j < y.size(); ++j )
				for ( a = x[i]; a < x[i+1]; ++a )
					for ( b = y[j]; b < y[j+1]; ++b )
						if ( dis(a,b,circular[k].x,circular[k].y) < circular[k].r ||
								dis(a+1,b,circular[k].x,circular[k].y) < circular[k].r ||
								dis(a,b+1,circular[k].x,circular[k].y) < circular[k].r ||
								dis(a+1,b+1,circular[k].x,circular[k].y) < circular[k].r ) {
							ans += flag[a][b];
							//flag[a][b] = 1;
						}
		/*
		for ( i = 0; i < x.size()-1; ++i )
			for ( j = 0; j < y.size()-1; ++j )
				for ( k = 0; k < n; ++k )
					if ( ( dis(x[i],y[j],circular[k].x,circular[k].y) < circular[k].r ) ||
							( dis(x[i+1],y[j],circular[k].x,circular[k].y) < circular[k].r ) ||
							( dis(x[i],y[j+1],circular[k].x,circular[k].y) < circular[k].r ) ||
							( dis(x[i+1],y[j+1],circular[k].x,circular[k].y) < circular[k].r ) ) {
						printf ( "i=%d\tj=%d:\n", i, j );
						printf ( "x[i]=%d y[j]=%d\n", x[i], y[j] );
						printf ( "x[i+1]=%d y[j]=%d\n", x[i+1], y[j] );
						printf ( "x[i]=%d y[j+1]=%d\n", x[i], y[j+1] );
						printf ( "x[i+1]=%d y[j+1]=%d\n", x[i+1], y[j+1] );
						cout << (x[i+1]-x[i])*(y[j+1]-y[j]) << endl;;
						printf ( "i=%d\tj=%d:\n", i, j );
						printf ( "x[i]=%d y[j]=%d\n", x[i], y[j] );
						printf ( "x[i+1]=%d y[j+1]=%d\n", x[i+1], y[j+1] );
						cout << ans << "\t";
						for ( a = x[i]; a < x[i+1]; ++a )
							for ( b = y[j]; b < y[j+1]; ++b ) {
								//printf ( "a=%d b=%d\n", a, b );
								if ( dis(a,b,circular[k].x,circular[k].y) < circular[k].r ||
										dis(a+1,b,circular[k].x,circular[k].y) < circular[k].r ||
										dis(a,b+1,circular[k].x,circular[k].y) < circular[k].r ||
										dis(a+1,b+1,circular[k].x,circular[k].y) < circular[k].r ) {
									++ans;
								}
							}
						cout << ans << endl;
						//ans += (x[i+1]-x[i])*(y[j+1]-y[j]);
						break;
					}
	*/
		printf ( "%d\n", ans );
	}
    return 0;
}
