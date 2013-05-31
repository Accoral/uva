/*************************************************************************
    > File Name: 507.cpp
    > Author: AC_coral
    > Mail: 313221234@qq.com 
    > Created Time: 2013年05月23日 星期四 09时01分05秒
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

int main()
{
	int T, n, i, x, start, end, tmp_start, route = 1;
	long long ans, s;
	scanf ( "%d", &T );
	while ( T-- ) {
		scanf ( "%d", &n );
		tmp_start = 1; start = end = ans = s = 0;
		for ( i = 1; i < n; ++i ) {
			scanf ( "%d", &x );
			s += x;
			if ( s < 0 ) {
				s = 0;
				tmp_start = i + 1;
			}
			if ( ans < s ) {
				ans = s;
				start = tmp_start;
			}
			if ( start == tmp_start && ans == s ) {
				end = i+1;
			}
		}
		//cout << ans << endl;
		if ( ans ) printf ( "The nicest part of route %d is between stops %d and %d\n", route++, start, end );
		else printf ( "Route %d has no nice parts\n", route++ );
	}
    return 0;
}
