/*************************************************************************
    > File Name: 10131.cpp
    > Author: Coral_Peng
    > Mail: 313221234@qq.com 
    > Created Time: 2013年04月30日 星期二 15时15分57秒
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

const int MAXN = 1024;
int G[MAXN][MAXN], x[MAXN], y[MAXN], dp[MAXN], n;
int dfs ( int i ) {
	int &ans = dp[i];
	if ( ans > 0 ) return ans;
	ans = 1;
	for ( int j = 1; j < n; ++j ) if ( G[i][j] ) ans = max ( ans, dfs(j) + 1 );
	return ans;
}
void print_ans ( int i ) {
	printf ( "%d\n", i+1 );
	for ( int j = 1; j < n; ++j ) if ( G[i][j] && dp[i] == dp[j] + 1 ) {
		print_ans ( j );
		break;
	}
}
int main()
{
	int i, j, max_ans, tmp, best;
	n = 0;
	while ( scanf ( "%d%d", x+n, y+n ) != EOF ) ++n;
	memset ( G, 0, sizeof(G) );
	for ( i = 0; i < n; ++i )
		for ( j = 0; j < n; ++j ) if ( x[i] < x[j] && y[i] > y[j] ) G[i][j] = 1;
	memset ( dp, 0, sizeof(dp) );
	max_ans = 0;
	for ( i = 0; i < n; ++i ) {
		tmp = dfs(i);
		if ( tmp > max_ans ) max_ans = tmp, best = i;
	}
	printf ( "%d\n", max_ans );
	print_ans ( best );
    return 0;
}
