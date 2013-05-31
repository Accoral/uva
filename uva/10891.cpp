/*************************************************************************
    > File Name: 10891.cpp
    > Author: Coral_Peng
    > Mail: 313221234@qq.com 
    > Created Time: 2013年05月05日 星期日 08时52分01秒
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
/*
		这是一道经典动态规划试题的变形，也是拓展。我们先看看它经典原型。
   题目：两个玩家A和B在玩一个取石子游戏，且每个石子都有它们各自的价值。在游戏中有这样一个规则：每次取一个石子必行从两端取，要么是最左端，要么是最右端，直到取完为止。两个玩家都非常聪明，他们每次都会去最优的结果。给他们N个石子，你能计算出玩家A，B各自的最后结果吗？假设总是玩家A先开局。
   对于这题，我们考虑best[i][j]表示开局者玩家A的i到j部分得到最大和，sum[i][j]表示从i到j和,由于只能从两端取石子，要么有从最左端，要么从最右端。则有转移方程：
	best[i][j]=sum[i][j]-min(best[i][j-1],best[i+1][j]); 目标状态：best[1][n]
那么推广到这题，可以取连续的，我们同样稍改变下即可。
	best[i][j]=sum[i][j]-min(best[i][j-k],best[i+k][j]);{1<=k=j-i+1}.
目标状态： best[1][n]-(sum[1][n]-best[1][n])
还有显然两者的初始化： best[i][i]=a[i];
   */
const int INF = 0x7fffffff;
int dp[128][128], vis[128][128], a[128], sum[128];
int dfs ( int i, int j ) {
	int &ans = dp[i][j];
	if ( vis[i][j] ) return ans;
	vis[i][j] = 1;
	if ( i == j ) return ans = a[i];
	ans = INF;
	int k;
	for ( k = i; k < j; ++k ) ans = min ( ans, dfs(i,k) );
	for ( k = i+1; k <= j; ++k ) ans = min ( ans, dfs(k,j) );
	ans = min ( ans, 0 );
	ans = sum[j] - sum[i-1] - ans;
	return ans;
}
int main()
{
	int n, i;
	while ( scanf ( "%d", &n ) != EOF && n ) {
		sum[0] = 0;
		for ( i = 1; i <= n; ++i ) {
			scanf ( "%d", &a[i] );
			sum[i] = sum[i-1] + a[i];
		}
		memset ( vis, 0, sizeof(vis) );
		printf ( "%d\n", 2*dfs(1,n)-sum[n] );
	}
    return 0;
}
