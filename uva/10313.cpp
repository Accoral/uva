/*************************************************************************
    > File Name: 10313.cpp
    > Author: Coral_Peng
    > Mail: 313221234@qq.com 
    > Created Time: 2013年05月08日 星期三 07时44分25秒
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
long long dp[301][301];
int main()
{
	int i, j, k, ans;
	memset ( dp, 0, sizeof(dp) );
	dp[0][0] = 1;
	for ( i = 1; i < 301; ++i )
		for ( j = 1; j < 301; ++j ) {
			if ( i >= j ) {
				for ( k = 0; k <= i-j && k <= j; ++k )
					dp[i][j] += dp[i-j][k];
			}
			//printf ( "dp[%d][%d] = %lld\n",i,j,dp[i][j] );
		}
	char s[150];
	while ( fgets ( s, 100, stdin ) ) {
		//printf ( "s=%s\n", s );
		long long ans = 0;
		int a, b, c;
		switch ( sscanf ( s, "%d%d%d", &a, &b, &c ) ) {
			case 1: 
				for ( i = 0; i <= a; ++i ) ans += dp[a][i];
				break;
			case 2:
				if ( b > 300 ) b = 300;
				for ( i = 0; i <= b; ++i ) ans += dp[a][i];
				break;
			case 3:
				if ( b > 300 ) b = 300;
				if ( c > 300 ) c = 300;
				for ( i = b; i <= c; ++i ) ans += dp[a][i];
				break;
		}
		printf ( "%lld\n", ans );
	}
    return 0;
}
