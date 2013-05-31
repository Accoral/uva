/*************************************************************************
    > File Name: 972.cpp
    > Author: AC_coral
    > Mail: 313221234@qq.com 
    > Created Time: 2013年05月24日 星期五 15时25分57秒
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
const int MUL = 1000;
double a[10*MUL+1];
int main()
{
	int i, n, left, right, j;
	double val, len;
	while ( scanf ( "%d", &n ) != EOF ) {
		for ( left = i = 0; i < n; ++i ) {
			scanf ( "%lf%lf", &val, &len );
			right = left + len * MUL;
			//printf ( "left=%d\tright=%d\n", left, right );
			for ( j = left; j < right; ++j ) a[j] = val;
			left = right;
		}

		scanf ( "%d", &n );
		for ( left = i = 0; i < n; ++i ) {
			scanf ( "%lf%lf", &val, &len );
			right = left + len * MUL;
			//printf ( "left=%d\tright=%d\n", left, right );
			for ( j = left; j < right; ++j ) a[j] = max ( a[j], val );
			left = right;
		}

		double ans = 11.0;
		for ( i = 0; i < 10000; ++i ) ans = min ( ans, a[i] );
		printf ( "%.3lf\n", ans );
	}
    return 0;
}
