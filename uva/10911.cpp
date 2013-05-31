/*************************************************************************
    > File Name: 10911.cpp
    > Author: Coral_Peng
    > Mail: 313221234@qq.com 
    > Created Time: 2013年05月06日 星期一 17时40分57秒
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
int x[20], y[20], n;
double dp[1<<20], vis[1<<20];
double dist ( int i, int j ) {
	return sqrt ( (x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]) );
}
double dfs ( int s ) {
	double &ans = dp[s];
	if ( vis[s] ) return ans;
	vis[s] = 1;
	if ( s == 0 ) return ans = 0;
	ans = INF;
	for ( int i = 0; i < n; ++i ) if ( s&(1<<i) ) {
		for ( int j = i+1; j < n; ++j ) if ( s&(1<<j) ) {
			ans = min ( ans, dfs(s^(1<<i)^(1<<j)) + dist(i,j) );
		}
	}
	return ans;
}
int main()
{
	int i, j, t=1, flag;
	char s[25];
	while ( scanf ( "%d", &n ) != EOF && n ) {
		n <<= 1;
		for ( i = 0; i < n; ++i ) scanf ( "%s%d%d", s, x+i, y+i );
		memset ( dp, 0, sizeof(dp) );

		for ( int S = 0; S < (1<<n); ++S ) {
			dp[S] = INF;
			flag = 1;
			for ( i = 0; i < n; ++i ) if ( S & (1<<i) ) break;

			for ( j = i+1; j < n; ++j ) if ( S & (1<<j) ) {
				flag = 0;
				dp[S] = min ( dp[S], dist(i,j)+dp[S^(1<<i)^(1<<j)] );
			}
			//}
			if ( flag ) dp[S] = 0;
			//printf ( "dp[%d]=%.2lf\n", S,dp[S] );
		}
		memset ( vis, 0, sizeof(vis) );

		printf ( "Case %d: %.2lf\n", t++, dp[(1<<n)-1] );
		//printf ( "Case %d: %.2lf\n", t++, dfs ( (1<<n)-1 ) );
	}
    return 0;
}
