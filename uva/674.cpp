/*************************************************************************
    > File Name: 674.cpp
    > Author: Coral_Peng
    > Mail: 313221234@qq.com 
    > Created Time: 2013年04月29日 星期一 17时47分46秒
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

int v[] = { 0, 1, 5, 10, 25, 50 }, dp[7500][6], n;
int dfs ( int s, int x ) {
	int &ans = dp[s][x];
	if ( ans >= 0 ) return ans;
	ans = 0;
	for ( int j = x; j <= 5; ++j ) if ( s >= v[j] ) ans += dfs ( s-v[j], j );
	return ans;
}
int main()
{
	int i, j;
	memset ( dp, -1, sizeof(dp) );
	for ( i = 0; i <= 5; ++i ) dp[0][i] = 1;
	dfs ( 7489, 1 );
	while ( scanf ( "%d", &n ) != EOF ) {
		printf ( "%d\n", dp[n][1] );
	}
    return 0;
}
