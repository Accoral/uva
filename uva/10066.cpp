/*************************************************************************
    > File Name: 10066.cpp
    > Author: Coral_Peng
    > Mail: 313221234@qq.com 
    > Created Time: 2013年04月30日 星期二 15时39分08秒
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
const int MAXN = 128;
int x[MAXN], y[MAXN], dp[MAXN][MAXN], n1, n2;

/*
void LCS ( ) {
	memset ( dp, 0, sizeof(dp) );
	int i, j;
	for ( i = 1; i <= n1; ++i )
		for ( j = 1; j <= n2; ++j )
			if ( x[i-1] == y[j-1] ) dp[i][j] = dp[i-1][j-1] + 1;
			else dp[i][j] = max ( dp[i-1][j], dp[i][j-1] );
}
*/
int dfs ( int i, int j ) {
	int &ans = dp[i][j];
	if ( ans != -1 ) return ans;
	if ( !i || !j ) return ans = 0;
	if ( x[i-1] == y[j-1] ) ans = dfs(i-1,j-1) + 1;
	else ans = max ( dfs(i-1,j), dfs(i,j-1) );
	return ans;
}
int main()
{
	int i, t = 1;
	while ( scanf ( "%d%d", &n1, &n2 ) != EOF ) {
		if ( !n1 & !n2 ) break;
		for ( i = 0; i < n1; ++i ) scanf ( "%d", x+i );
		for ( i = 0; i < n2; ++i ) scanf ( "%d", y+i );
		//LCS ( );
		printf ( "Twin Towers #%d\n", t++ );
		memset ( dp, -1, sizeof(dp) );
		printf ( "Number of Tiles : %d\n\n", dfs ( n1, n2 ) );
	}
    return 0;
}
