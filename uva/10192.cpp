/*************************************************************************
    > File Name: 10192.cpp
    > Author: Coral_Peng
    > Mail: 313221234@qq.com 
    > Created Time: 2013年04月30日 星期二 17时45分17秒
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
char x[MAXN], y[MAXN], dp[MAXN][MAXN];
int LCS ( ) {
	memset ( dp, 0, sizeof(dp) );
	int x_len = strlen ( x ) - 1;
	int y_len = strlen ( y ) - 1;
	int i, j;
	for ( i = 1; i <= x_len; ++i )
		for ( j = 1; j <= y_len; ++j )
			if ( x[i-1] == y[j-1] ) dp[i][j] = dp[i-1][j-1] + 1;
			else dp[i][j] = max ( dp[i-1][j], dp[i][j-1] );
	return dp[x_len][y_len];
}
int main()
{
	int t = 1;
	while ( fgets ( x, MAXN, stdin ) ) {
		if ( x[0] == '#' ) break;
		fgets ( y, MAXN, stdin );
		printf ( "Case #%d: you can visit at most %d cities.\n", t++, LCS() );
	}
    return 0;
}
