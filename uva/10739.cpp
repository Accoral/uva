/*************************************************************************
    > File Name: 10739.cpp
    > Author: Coral_Peng
    > Mail: 313221234@qq.com 
    > Created Time: 2013年05月03日 星期五 10时49分42秒
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
const int MAXN = 1010;
const int INF = 0x7fffffff;
string str;
int dp[MAXN][MAXN], vis[MAXN][MAXN];
int min_fun ( int x, int y, int z ) {
	return min ( x, min ( y, z ) );
}
int dfs ( int i, int j ) {
	int &ans = dp[i][j];
	if ( vis[i][j] ) return ans;
	vis[i][j] = 1;
	ans = INF;

	if ( i > j ) return ans = 0;

	if ( str[i] == str[j] ) ans = dfs(i+1,j-1);
	else ans = min_fun ( dfs(i,j-1), dfs(i+1,j), dfs(i+1,j-1) ) + 1;
	return ans;
}
int main()
{
	int T;
	scanf ( "%d", &T );
	for ( int t = 1; t <= T; ++t ) {
		cin >> str;
		memset ( vis, 0, sizeof(vis) );
		printf ( "Case %d: %d\n", t, dfs ( 0, str.length()-1 ) );
	}
    return 0;
}
