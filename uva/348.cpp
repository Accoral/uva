/*************************************************************************
    > File Name: 348.cpp
    > Author: Coral_Peng
    > Mail: 313221234@qq.com 
    > Created Time: 2013年04月30日 星期二 19时28分20秒
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
const int INF = 0x7FFFFFFF;

int x[15], y[15], dp[15][15], n;
int dfs ( int i, int j ) {
	int &ans = dp[i][j];
	if ( ans != -1 ) return ans;
	if ( i == j ) return ans = 0;
	ans = INF;
	for ( int k = 0; k < n; ++k ) if ( i <= k && (k+1) <= j ) ans = min ( dfs ( i, k ) + dfs ( k+1, j ) + x[i]*y[k]*y[j], ans );
	return ans;
}
void print_ans ( int i, int j ) {
	if ( i == j ) {
		printf ( "A%d", i+1 );
		return;
	}
	for ( int k = 0; k < n; ++k ) if ( i <= k && (k+1) <= j && dp[i][j] == dp[i][k] + dp[k+1][j] + x[i]*y[k]*y[j] ) {
		printf ( "(" );
	   	print_ans ( i, k );
		printf ( " x " );
	   	print_ans ( k+1, j );
		printf ( ")" );
		break;
	}
}
int main()
{
	int i, t = 1;
	while ( scanf ( "%d", &n ) != EOF && n ) {
		for ( i = 0; i < n; ++i ) scanf ( "%d%d", x+i, y+i );
		memset ( dp, -1, sizeof(dp) );
		dfs ( 0, n-1 );
		printf ( "Case %d: ", t++ );
		print_ans ( 0, n-1 );
		printf ( "\n" );
	}
    return 0;
}
