/*************************************************************************
    > File Name: 624.cpp
    > Author: Coral_Peng
    > Mail: 313221234@qq.com 
    > Created Time: 2013年04月30日 星期二 21时09分47秒
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

int v[25], dp[25][10010], n, path[25][10010];
int main()
{
	int C, i, j;
	while ( scanf ( "%d", &C ) != EOF ) {
		scanf ( "%d", &n );
		//memset ( dp, 0, sizeof(dp) );
		memset ( path, 0, sizeof(path) );
		for ( i = 1; i <= n; ++i ) {
			scanf ( "%d", &v[i] );
			for ( j = 0; j <= C; ++j ) {
				dp[i][j] = ( i==1 ? 0 : dp[i-1][j] );
				if ( j >= v[i] ) {
					if ( dp[i][j] < dp[i-1][j-v[i]] + v[i] ) {
						dp[i][j] = dp[i-1][j-v[i]] + v[i];
						//printf ( "%d ", i );
						path[i][j] = 1;
					}
				}
			}
		}
		int c=C;
		for ( i = n; i >= 1; --i ) if ( path[i][c] ) printf ( "%d ", v[i] ), c-=v[i];
		printf ( "sum:%d\n",  dp[n][C] );
	}
    return 0;
}
