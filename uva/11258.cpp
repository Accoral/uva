/*************************************************************************
    > File Name: 11258.cpp
    > Author: Coral_Peng
    > Mail: 313221234@qq.com 
    > Created Time: 2013年05月08日 星期三 09时53分14秒
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
long long dp[205];
int main()
{
	int T, i, j, len;
	long long num;
	char s[201];
	scanf ( "%d", &T );
	while ( T-- ) {
		scanf ( "%s", s );
		memset ( dp, 0, sizeof(dp) );
		len = strlen ( s );
		for ( i = len-1; i >= 0; --i ) {
			num = 0;
			for ( j = i; j < len; ++j ) {
				num = num * 10 + s[j]-'0';
				if ( num > INF ) break;
				dp[i] = max ( dp[i], dp[j+1] + num );
			//printf ( "i=%d j=%d: %lld\tdp[%d](%d)+%d=\t%lld\n", i, j, dp[i], j,dp[j+1],num,dp[j+1]+num );
			}
			//printf ( "%d: %lld\n", i, dp[i] );
		}
		printf ( "%lld\n", dp[0] );
	}
    return 0;
}
