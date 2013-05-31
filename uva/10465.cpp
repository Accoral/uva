/*************************************************************************
    > File Name: 10465.cpp
    > Author: Coral_Peng
    > Mail: 313221234@qq.com 
    > Created Time: 2013年05月01日 星期三 10时08分32秒
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
int dp[10010], v[2], t, vis[10010];
int dfs ( int s ) {
	int &ans = dp[s];
	if ( ans != -1 ) return ans;
	ans = -INF;
	for ( int i = 0; i < 2; ++i ) if ( s >= v[i] )
		ans = max ( ans, dfs ( s-v[i] ) + 1 );
	return ans;
}
int main()
{
	while ( scanf ( "%d%d%d", v, v+1, &t ) != EOF ) {
		int i;
		for ( i = t; i >= 1; --i ) {
			memset ( dp, -1, sizeof(dp) );
			dp[0] = 0;
			dfs(i);
			if ( dp[i] > 0 ) break;
		}
		if ( i == t ) printf ( "%d\n", dp[t] );
		else printf ( "%d %d\n", dp[i], t-i );
	}
    return 0;
}
