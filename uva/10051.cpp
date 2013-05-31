/*************************************************************************
    > File Name: 10051.cpp
    > Author: Coral_Peng
    > Mail: 313221234@qq.com 
    > Created Time: 2013年05月01日 星期三 20时21分07秒
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

int n, face[512][6], G[512][512][6][6], dp[512][6], vis[512][6];
char top[][15] = { "front", "top", "left", "right", "bottom", "back", };
int dfs ( int i, int k ) {
	int &ans = dp[i][k];
	if ( vis[i][k] ) return ans;
	vis[i][k] = 1;
	ans = 1;
	for ( int j = 0; j < n; ++j )
		for ( int k1 = 0; k1 < 6; ++k1 )
			if ( G[i][j][5-k][k1] ) ans = max ( ans, dfs(j,k1)+1 );
	return ans;
}
void print_ans ( int i, int k ) {
	printf ( "%d %s\n", i+1, top[k] );
	int flag = 0;
	for ( int j = 0; j < n; ++j ) {
		flag = 0;
		for ( int k1 = 0; k1 < 6; ++k1 ) {
			if ( G[i][j][5-k][k1] && dp[i][k] == dp[j][k1] + 1 ) {
				print_ans ( j, k1 );
				flag = 1;
				break;
			}
		}
		if ( flag ) break;
	}
}
int main()
{
	int i, j, k, k1, ans, besti, bestk, t = 0;
	while ( scanf ( "%d", &n ) != EOF && n ) {
		if ( t ) printf ( "\n" );
		printf ( "Case #%d\n", ++t );
		for ( i = 0; i < n; ++i ) scanf ( "%d%d%d%d%d%d", face[i], face[i]+5, face[i]+2, face[i]+3, face[i]+1, face[i]+4 );
		memset ( G, 0, sizeof(G) );
		for ( i = 0; i < n; ++i )
			for ( j = i+1; j < n; ++j )
				for ( k = 0; k < 6; ++k )
					for ( k1 = 0; k1 < 6; ++k1 )
						if ( face[i][k] == face[j][k1] )
							G[i][j][k][k1] = 1;
		memset ( vis, 0, sizeof(vis) );
		for ( besti = bestk = ans = i = 0; i < n; ++i )
			for ( k = 0; k < 6; ++k )
				if ( ans < dfs(i,k) ) ans = dfs(i,k), besti = i, bestk = k;
		printf ( "%d\n", ans );
		print_ans ( besti, bestk );
	}
    return 0;
}
