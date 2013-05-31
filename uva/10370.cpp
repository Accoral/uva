/*************************************************************************
    > File Name: 10370.cpp
    > Author: AC_coral
    > Mail: 313221234@qq.com 
    > Created Time: 2013年05月24日 星期五 12时48分35秒
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
int a[1024];
int main()
{
	int T, sum, cnt, i, n;
	double average;
	scanf ( "%d", &T );
	while ( T-- ) {
		scanf ( "%d", &n );
		for ( sum = i = 0; i < n; ++i ) {
			scanf ( "%d", a+i );
			sum += a[i];
		}
		average = (double)sum / n;
		for ( cnt = i = 0; i < n; ++i ) if ( a[i] > average ) ++cnt;
		printf ( "%.3lf%%\n", 100*(double)cnt / n );
	}
    return 0;
}
