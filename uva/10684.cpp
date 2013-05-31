/*************************************************************************
    > File Name: 10684.cpp
    > Author: AC_coral
    > Mail: 313221234@qq.com 
    > Created Time: 2013年05月09日 星期四 10时10分55秒
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
const int MAXN = 10010;
int N, a[MAXN], dp[MAXN];
int main()
{
	int i, ans;
	while ( scanf ( "%d", &N ) != EOF && N ) {
		for ( i = 1; i <= N; ++i ) scanf ( "%d", a+i );
		ans = dp[0] = 0;
		for ( i = 1; i <= N; ++i ) {
			if ( dp[i-1] + a[i] > 0 ) dp[i] = dp[i-1] + a[i];
			else dp[i] = 0;
			ans = max ( ans, dp[i] );
		}
		if ( ans ) printf ( "The maximum winning streak is %d.\n", ans );
		else printf ( "Losing streak.\n" );
	}
    return 0;
}
