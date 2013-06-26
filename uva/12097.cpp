/*************************************************************************
    > File Name: 12097.cpp
    > Author: AC_coral❤
    > Mail: 313221234@qq.com 
    > Created Time: 2013年06月26日 星期三 17时01分05秒
 ************************************************************************/

#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <climits>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <map>
#include <set>

using namespace std;
const double eps = 1E-5;
const double PI = acos(-1);
double A[10000+10];
int F, N;
bool ok(double x) {
	int cnt = 0;
	for ( int i = 0; i < N; ++i ) cnt += floor(A[i]/x);
	return cnt >= F+1;
}
int main()
{
	int T, i, r;
	double maxa;
	scanf ( "%d", &T );
	while ( T-- ) {
		scanf ( "%d%d", &N, &F );
		maxa = -1;
		for ( i = 0; i < N; ++i ) {
			scanf ( "%d", &r );
			A[i] = PI*r*r;
			maxa = max(maxa, A[i]);
		}
		double L = 0, R = maxa, M;
		while ( R-L > eps ) {
			M = L + (R-L)/2;
			if ( ok(M) ) L = M;
			else R = M;
		}
		printf ( "%.4lf\n", L );
	}
  return 0;
}
