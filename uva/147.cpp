/*************************************************************************
    > File Name: 147.cpp
    > Author: Coral_Peng
    > Mail: 313221234@qq.com 
    > Created Time: 2013年04月30日 星期二 17时58分54秒
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
int v[] = { 5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000 };
long long dp[30010][11];
long long dfs ( int s, int x ) {
	long long &ans = dp[s][x];
	if ( ans != -1 ) return ans;
	ans = 0;
	for ( int i = x; i < 11; ++i ) if ( s >= v[i] ) ans += dfs ( s-v[i], i );
	return ans;
}
int main()
{
	char c[10];
	memset ( dp, -1, sizeof(dp) );
	for ( int i = 0; i < 11; ++i ) dp[0][i] = 1;
	dfs ( 30000, 0 );
	while ( scanf ( "%s", c ) != EOF ) {
		if ( strcmp ( c, "0.00" ) == 0 ) break;
		int tmp = 0;
		for ( int i = 0; i < strlen(c); ++i ) if ( c[i] != '.' ) tmp = tmp*10 + c[i] - '0';
		//printf ( "tmp=%d\n", tmp );
		printf ( "%6s%17lld\n", c, dp[tmp][0] );
	}
    return 0;
}
