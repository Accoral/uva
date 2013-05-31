/*************************************************************************
    > File Name: 10038.cpp
    > Author: AC_coral
    > Mail: 313221234@qq.com 
    > Created Time: 2013年05月10日 星期五 12时04分38秒
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
const int MAXN = 3010;
int diff[MAXN], a[MAXN];
int main()
{
	int i, n, ok;
	while ( scanf ( "%d", &n ) != EOF ) {
		scanf ( "%d", a );
		for ( i = 1; i < n; ++i ) {
			scanf ( "%d", a + i );
			diff[i] = abs(a[i] - a[i-1]);
		}
		sort ( diff+1, diff+n );
		//for ( i = 1; i < n; ++i ) printf ( "%d ", diff[i] ); printf ( "\n" );
		ok = 1;
		for ( i = 1; i < n; ++i ) if ( i != diff[i] ) {
			ok = 0;
			break;
		}
		if ( ok ) printf ( "Jolly\n" );
		else printf ( "Not jolly\n" );
	}
    return 0;
}
