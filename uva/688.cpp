/*************************************************************************
    > File Name: 688.cpp
    > Author: AC_coral
    > Mail: 313221234@qq.com 
    > Created Time: 2013年05月24日 星期五 18时41分13秒
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
const int N = 105;
struct {
	double x, y, r;
}rec[N];
double x[N*2], y[N*2];
int main()
{
	int i, n, t = 1, j, k;
	while ( scanf ( "%d", &n ) != EOF && n ) {
		for ( i = 0; i < n; ++i ) {
			scanf ( "%lf%lf%lf", &rec[i].x, &rec[i].y, &rec[i].r );
			x[i] = rec[i].x - rec[i].r; x[i+n] = rec[i].x + rec[i].r;
			y[i] = rec[i].y - rec[i].r; y[i+n] = rec[i].y + rec[i].r;
		}
		sort ( x, x + 2*n );
		sort ( y, y + 2*n );
		double sum = 0.0;
		for ( i = 0; i < 2*n-1; ++i )
			for ( j = 0; j < 2*n-1; ++j )
				for ( k = 0; k < n; ++k ) if ( rec[k].x-rec[k].r <= x[i] && x[i+1] <= rec[k].x+rec[k].r && rec[k].y-rec[k].r <= y[j] && y[j+1] <= rec[k].y+rec[k].r ) {
					sum += ( x[i+1]-x[i] ) * ( y[j+1] - y[j] );
					break;
				}
		printf ( "%d %.2lf\n", t++, sum );
	}
    return 0;
}
