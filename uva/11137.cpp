/*************************************************************************
    > File Name: 11137.cpp
    > Author: Coral_Peng
    > Mail: 313221234@qq.com 
    > Created Time: 2013年05月03日 星期五 09时25分09秒
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
int v[22];
long long dp[10010];
/*
   dp[i, j]表示前i种货币表示j钱有多少种表示方法。

   1. dp[i-1, j] 用前i-1种货币表示j

   2. dp[i, j-v] 前i种货币表示j-v，再加上v便是必须有第i种货币来表示j

   动态方程：
   dp[i][j] = dp[i-1][j] + dp[i][j-v];

   仔细发现可以压缩成一维数组 dp[j] = dp[j] + dp[j-v]。
   */
void init ( ) {
	int i, j;
	memset ( dp, 0, sizeof(dp) );
	for ( dp[0] = i = 1; i < 22; ++i ) {
		for ( j =0; j <= 10000; ++j )
			if ( j >= v[i] ) dp[j] += dp[j-v[i]];
	}
}
int main()
{
	int s;
	for ( int i = 0; i < 22; ++i ) v[i] = i*i*i;
	init();
	while ( scanf ( "%d", &s ) != EOF ) {
		printf ( "%lld\n", dp[s] );
	}
    return 0;
}
