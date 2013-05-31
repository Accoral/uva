/*************************************************************************
    > File Name: 111.cpp
    > Author: Coral_Peng
    > Mail: 313221234@qq.com 
    > Created Time: 2013年04月29日 星期一 14时25分33秒
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

int dp[25][25];
void LCS ( int *x, int *y, int x_len, int y_len ) {
	int i, j;
	for ( i = 0; i <= x_len; ++i ) dp[i][0] = 0;
	for ( j = 0; j <= y_len; ++j ) dp[0][j] = 0;
	for ( i = 1; i <= x_len; ++i )
		for ( j = 1; j <= y_len; ++j )
			if ( x[i] == y[j] ) dp[i][j] = dp[i-1][j-1] + 1;
			else dp[i][j] = max ( dp[i-1][j], dp[i][j-1] );
}
int main()
{
	int n, x[25], y[25], i, tmp;
	scanf ( "%d", &n );
	for ( i = 0; i < n; ++i ) {
		scanf ( "%d", &tmp );
		x[tmp] = i+1;
	}
	while ( scanf ( "%d", &tmp ) != EOF ) {
		y[tmp] = 1;
		for ( i = 1; i < n; ++i ) {
			scanf ( "%d", &tmp );
			y[tmp] = i+1;
		}
		LCS ( x, y, n, n );
		printf ( "%d\n", dp[n][n] );
	}
    return 0;
}
