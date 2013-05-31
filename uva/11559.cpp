/*************************************************************************
    > File Name: 11559.cpp
    > Author: AC_coral
    > Mail: 313221234@qq.com 
    > Created Time: 2013年05月08日 星期三 22时24分43秒
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
const int INF = 0x7fffffff;
int main()
{
	int N, B, H, W, p, a[15], i, ans;
	while ( scanf ( "%d%d%d%d", &N, &B, &H, &W ) != EOF ) {
		ans = INF;
		while ( H-- ) {
			scanf ( "%d", &p );
			for ( i = 0; i < W; ++i ) scanf ( "%d", a+i );
			sort ( a, a + W );
			for ( i = 0; i < W; ++i ) if ( a[i] >= N ) {
				ans = min ( ans, N*p );
				break;
			}
		}
		if ( ans > B ) printf ( "stay home\n" );
		else printf ( "%d\n", ans );
	}
    return 0;
}
