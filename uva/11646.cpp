/*************************************************************************
    > File Name: 11646.cpp
    > Author: AC_coral❤
    > Mail: 313221234@qq.com 
    > Created Time: 2013年06月26日 星期三 15时59分41秒
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
const double eps = 1E-10;
const double PI = acos(-1);
int main()
{
	double a, b, x, y;
	int cases = 1;
	while ( scanf ( "%lf : %lf", &a, &b ) != EOF ) {
		double ang1 = atan(a/b);
		double ang2 = PI - 2*ang1;
		x = 200/(1+ang2/(2*sin(ang1)));
		y = x*b/a;
		//Case 1: 117.1858168913 78.1238779275
		printf ( "Case %d: %.10lf %.10lf\n", cases++, x, y );
	}
  return 0;
}
