/*************************************************************************
    > File Name: 437.cpp
    > Author: Coral_Peng
    > Mail: 313221234@qq.com 
    > Created Time: 2013年05月01日 星期三 16时26分22秒
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
const int MAXN = 35*3;
pair < int, int > base[MAXN];
int height[MAXN], dp[MAXN], cnt, G[MAXN][MAXN], vis[MAXN];
int dfs ( int i ) {
	int &ans = dp[i];
	if ( vis[i] ) return ans;
	vis[i] = 1;
	ans = height[i];
	for ( int j = 0; j < cnt; ++j ) if ( G[i][j] ) ans = max ( ans , dfs(j) + height[i] );
	return ans;
}
int main()
{
	int n, t = 1, x, y, z, i, j, tmp;
	while ( scanf ( "%d", &n ) != EOF && n ) {
		for ( cnt = i = 0; i < n; ++i ) {
			scanf ( "%d%d%d", &x, &y, &z );
			base[cnt] = make_pair( min(x,y), max(x,y) ), height[cnt++] = z;
			base[cnt] = make_pair( min(x,z), max(x,z) ), height[cnt++] = y;
			base[cnt] = make_pair( min(y,z), max(y,z) ), height[cnt++] = x;
		}
		memset ( G, 0, sizeof(G) );
		for ( i = 0; i < cnt; ++i )
			for ( j = 0; j < cnt; ++j )
				if ( base[i].first > base[j].first && base[i].second > base[j].second ) G[i][j] = 1;
		int max_ans = 0;
		for ( i = 0; i < cnt; ++i ) {
			memset ( vis, 0, sizeof(vis) );
			tmp = dfs ( i );
			if ( tmp > max_ans ) max_ans = tmp;
		}
		printf ( "Case %d: maximum height = %d\n", t++, max_ans );
	}
    return 0;
}
