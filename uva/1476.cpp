/*************************************************************************
    > File Name: 1476.cpp
    > Author: AC_coral❤
    > Mail: 313221234@qq.com 
    > Created Time: 2013年06月28日 星期五 13时44分55秒
 ************************************************************************/

#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <climits>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>

using namespace std;
const int INF = 0x7FFFFFFF;
const double eps = 1E-9;//本题eps <= 1E-9 能ac
const int maxn = 10000+10;
int n, a[maxn], b[maxn], c[maxn];
double F(double x) {
	double ans = a[0]*x*x + b[0]*x + c[0];
	for ( int i = 1; i < n; ++i ) ans = max(ans, a[i]*x*x+b[i]*x+c[i]);
	return ans;
}
int main()
{
	int T, i;
	scanf ( "%d", &T );
	while ( T-- ) {
		scanf ( "%d", &n );
		for ( i = 0; i < n; ++i ) scanf ( "%d%d%d", a+i, b+i, c+i );
		double L = 0, R = 1000, m1, m2;
		//while ( R-L > eps ) {
		for ( i = 0; i < 100; ++i ) {
			m1 = L + (R-L)/3;
			m2 = R - (R-L)/3;
			if ( F(m1) < F(m2) ) R = m2;
			else L = m1;
		}
		printf ( "%.4lf\n", F(L) );
	}
  return 0;
}
