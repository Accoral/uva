/*************************************************************************
    > File Name: 11151.cpp
    > Author: Coral_Peng
    > Mail: 313221234@qq.com 
    > Created Time: 2013年05月04日 星期六 09时34分05秒
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

int dp[1024][1024], vis[1024][1024];
char s[1024];
int dfs ( int i, int j ) {
	int &ans = dp[i][j];
	if ( vis[i][j] ) return ans;
	vis[i][j] = 1;
	ans = 0;
	if ( i > j ) return ans = 0;
	if ( i == j ) return ans = 1;

	ans = max ( dfs(i+1,j), dfs(i,j-1) );
	if ( s[i] == s[j] ) ans = max ( ans, dfs(i+1,j-1)+2 );
	return ans;
}
int main()
{
	int T;
	scanf ( "%d", &T );
	getchar ( );
	while ( T-- ) {
		fgets ( s, 1024, stdin );
		memset ( vis, 0, sizeof(vis) );
		printf ( "%d\n", dfs ( 0, strlen(s)-2 ) );
	}
    return 0;
}
