/*************************************************************************
    > File Name: 10069.cpp
    > Author: Coral_Peng
    > Mail: 313221234@qq.com 
    > Created Time: 2013年05月04日 星期六 20时09分38秒
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

const int MAXX = 10010;
const int MAXZ = 110;
char x[MAXX], z[MAXZ];
int dp[MAXZ][MAXX][30];

void add ( int i, int j ) { 
	for ( int k = 0; k < 30; ++k ) { 
		dp[i][j][k+1] += ( dp[i][j-1][k] + dp[i-1][j-1][k] ) / 10000;
		dp[i][j][k] += ( dp[i][j-1][k] + dp[i-1][j-1][k] ) % 10000;
	}
}
int main()
{
	int T, i, j, cnt, k, len_x, len_z;
	scanf ( "%d", &T );
	while ( T-- ) {
		scanf ( "%s%s", x, z );
		len_x = strlen ( x ); len_z = strlen ( z );
		memset ( dp, 0, sizeof(dp) );

		/*
		cnt = 0;
		for ( j = 0; j < len_x; ++j ) 
			if ( z[0] == x[j] ) dp[0][j][0] = ++cnt;
			else dp[0][j][0] = cnt;
		*/
		for ( j = 0; j <= len_x; ++j ) dp[0][j][0] = 1;

		for ( i = 1; i <= len_z; ++i )
			for ( j = 1; j <= len_x; ++j )
				if ( z[i-1] != x[j-1] ) {
					//dp[i][j] = dp[i][j-1];
					for ( k = 0; k < 30; ++k ) dp[i][j][k] = dp[i][j-1][k];
				}
				else {
					//dp[i][j] = dp[i][j-1] + dp[i-1][j-1];
					add ( i, j );
				}
		for ( i = 30-1; dp[len_z][len_x][i] == 0 && i >= 0; --i );
		printf ( "%d", dp[len_z][len_x][i] );
		for ( --i; i >= 0; --i ) printf ( "%04d", dp[len_z][len_x][i] );
		printf ( "\n" );
	}
    return 0;
}
