/*************************************************************************
    > File Name: 357.cpp
    > Author: Coral_Peng
    > Mail: 313221234@qq.com 
    > Created Time: 2013年04月30日 星期二 19时03分06秒
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
int v[] = { 1, 5, 10, 25, 50 };
long long dp[30010][5];
long long dfs ( int s, int x ) {
	long long &ans = dp[s][x];
	if ( ans != -1 ) return ans;
	ans = 0;
	for ( int i = x; i < 5; ++i ) if ( s >= v[i] ) ans += dfs ( s-v[i], i );
	return ans;
}
int main()
{
	memset ( dp, -1, sizeof(dp) );
	for ( int i = 0; i < 5; ++i ) dp[0][i] = 1;
	dfs ( 30000, 0 );
	int x;
	while ( scanf ( "%d", &x ) != EOF ) {
		if ( dp[x][0] == 1 ) printf ( "There is only 1 way to produce %d cents change.\n", x );
		else printf ( "There are %lld ways to produce %d cents change.\n", dp[x][0], x );
	}
    return 0;
}
