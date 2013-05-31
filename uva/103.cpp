/*************************************************************************
    > File Name: 103.cpp
    > Author: Coral_Peng
    > Mail: 313221234@qq.com 
    > Created Time: 2013年04月30日 星期二 13时11分28秒
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

const int MAXN = 100;
vector < int > v[MAXN];
int dp[MAXN], k, G[MAXN][MAXN];
int dfs ( int x ) {
	int &ans = dp[x];
	if ( ans > 0 ) return ans;
	ans = 1;
	for ( int i = 0; i < k; ++i ) if ( G[x][i] ) ans = max ( ans, dfs(i)+1 );
	return ans;
}
int first;
void print_ans ( int x ) {
	if ( first ) printf ( "%d", x+1 ), first = 0;
	else printf ( " %d", x+1 );
	for ( int i = 0; i < k; ++i ) if ( G[x][i] && dp[x] == dp[i]+1 ) {
		print_ans ( i );
		break;
	}
}
int main()
{
	int n, i, j, x, flag;
	while ( scanf ( "%d%d", &k, &n ) != EOF ) {
		for ( i = 0; i < k; ++i ) {
			v[i].clear ( );
			for ( j = 0; j < n; ++j ) {
				scanf ( "%d", &x );
				v[i].push_back ( x );
			}
			sort ( v[i].begin(), v[i].end() );
		}
		memset ( G, 0, sizeof(G) );
		for ( i = 0; i < k; ++i ) {
			for ( j = 0; j < k; ++j ) {
				flag = 1;
				for ( x = 0; x < n; ++x ) if ( v[i][x] >= v[j][x] ) { flag = 0; break; }
				if ( flag ) G[i][j] = 1;
			}
		}
		int max_ans = -1, best, tmp;
		memset ( dp, -1, sizeof(dp) );
		for ( i = 0; i < k; ++i ) {
			tmp = dfs ( i );
			if ( tmp > max_ans ) max_ans = tmp, best = i;
		}
		printf ( "%d\n", max_ans );
		first = 1;
		print_ans ( best );
		printf ( "\n" );
	}
    return 0;
}
