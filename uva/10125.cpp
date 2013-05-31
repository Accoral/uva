/*************************************************************************
    > File Name: 10125.cpp
    > Author: AC_coral
    > Mail: 313221234@qq.com 
    > Created Time: 2013年05月26日 星期日 13时39分07秒
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
int main()
{
	//printf ( "%d %d\n", 536870911*3, -INF );
	int n, i, a[1024], j, k, tmp, ans, ok;
	while ( scanf ( "%d", &n ) != EOF && n ) {
		for ( i = 0; i < n; ++i ) scanf ( "%d", a+i );
		sort ( a, a+n );
		ans = -INF; ok = 1;
		for ( int x = n-1; ok && x >= 0; --x )
			for ( i = 0; ok && i < n; ++i )
				for ( j = i+1; ok && j < n; ++j )
					for ( k = j+1; ok && k < n; ++k ) {
						tmp = a[i]+a[j]+a[k];
						if ( tmp == a[x] )
						if ( tmp != a[i] && tmp != a[j] && tmp != a[k] ) ans = a[x], ok = 0;
					}
		if ( ans != -INF ) printf ( "%d\n", ans );
		else printf ( "no solution\n" );
	}
    return 0;
}
