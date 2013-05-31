/*************************************************************************
    > File Name: 10003.cpp
    > Author: Coral_Peng
    > Mail: 313221234@qq.com 
    > Created Time: 2013年04月30日 星期二 10时03分03秒
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

int c[55], dp[55][55], n;
int dfs ( int x, int y ) {
	int &ans = dp[x][y];
	if ( ans != -1 ) return ans;
	ans = 0x7fffffff;
	if ( (x+1) == y ) return ans = 0;
	for ( int k = x+1; k < y; ++k ) ans = min ( ans, dfs(x,k) + dfs(k,y) + c[y]-c[x] );
	return ans;
}
int main()
{
	int l, i;
	while ( scanf ( "%d", &l ) != EOF && l ) {
		c[0] = 0;
		scanf ( "%d", &n );
		for ( i = 1; i <= n; ++i ) scanf ( "%d", c+i );
		c[i] = l;
		memset ( dp, -1, sizeof(dp) );
		printf ( "The minimum cutting is %d.\n", dfs ( 0, n+1 ) );
	}
    return 0;
}
