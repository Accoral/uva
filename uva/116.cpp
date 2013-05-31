/*************************************************************************
    > File Name: 116.cpp
    > Author: Coral_Peng
    > Mail: 313221234@qq.com 
    > Created Time: 2013年04月30日 星期二 14时16分13秒
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

const int INF = 0x7fffffff;
int mat[15][105], dp[15][105], m, n, vis[15][105];
int min_fun ( int x, int y, int z ) {
	return min ( x, min ( y, z ) );
}
int dfs ( int x, int y ) {
	int &ans = dp[x][y];
	if ( vis[x][y] ) return ans;
	vis[x][y] = 1;
	ans = min_fun ( dfs((x-1+m)%m, y+1), dfs(x, y+1), dfs((x+1+m)%m, y+1) ) + mat[x][y];
	return ans;
}
int first;
void print_ans ( int x, int y ) {
	if ( y == n ) return;
	if ( first ) printf ( "%d", x+1 ), first = 0;
	else printf ( " %d", x+1 );
	vector < int > v;
	v.push_back ( (x-1+m)%m ), v.push_back ( x ), v.push_back ( (x+1+m)%m );
	sort ( v.begin ( ), v.end ( ) );
	for ( int i = 0; i < v.size(); ++i ) if ( dp[x][y] == dp[v[i]][y+1] + mat[x][y] ) {
		print_ans ( v[i], y+1 );
		break;
	}
}
int main()
{
	int i, j;
	while ( scanf ( "%d%d", &m, &n ) != EOF ) {
		for ( i = 0; i < m; ++i )
			for ( j = 0; j < n; ++j ) scanf ( "%d", &mat[i][j] );
		int min_ans = INF, best, tmp;
		memset ( vis, 0, sizeof(vis) );
		for ( i = 0; i < m; ++i ) dp[i][n-1] = mat[i][n-1], vis[i][n-1] = 1;
		for ( i = 0; i < m; ++i ) {
			tmp = dfs ( i, 0 );
			if ( min_ans > tmp ) min_ans = tmp, best = i;
		}
		first = 1;
		print_ans ( best, 0 );
		printf ( "\n" );
		printf ( "%d\n", min_ans );
	}
    return 0;
}
