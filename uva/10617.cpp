/*************************************************************************
    > File Name: 10617.cpp
    > Author: Coral_Peng
    > Mail: 313221234@qq.com 
    > Created Time: 2013年05月03日 星期五 21时02分01秒
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

char s[70];
long long dp[70][70];
int vis[70][70];
long long dfs ( int i, int j ) {
	long long &ans = dp[i][j];
	if ( vis[i][j] ) return ans;
	vis[i][j] = 1;
	if ( i > j ) return ans = 0;
	if ( s[i] == s[j] ) ans = dfs ( i+1, j ) + dfs ( i, j-1 ) + 1;
	else ans = dfs ( i+1, j ) + dfs ( i, j-1 ) - dfs ( i+1, j-1 );
	return ans;
}
int main()
{
	int T;
	scanf ( "%d", &T );
	while ( T-- ) {
		scanf ( "%s", s );
		memset ( vis, 0, sizeof(vis) );
		printf ( "%lld\n", dfs ( 0, strlen(s)-1 ) );
	}
    return 0;
}
