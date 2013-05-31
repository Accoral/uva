/*************************************************************************
    > File Name: 10453.cpp
    > Author: Coral_Peng
    > Mail: 313221234@qq.com 
    > Created Time: 2013年05月04日 星期六 10时40分20秒
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

const int MAXN = 1024;
char s[MAXN];
int dp[MAXN][MAXN], vis[MAXN][MAXN];
int dfs ( int i, int j ) {
	int &ans = dp[i][j];
	if ( vis[i][j] ) return ans;
	vis[i][j] = 1;
	ans = 0;
	if ( i > j ) return ans = 0;
	if ( s[i] == s[j] ) ans = dfs(i+1,j-1);
	else ans = min ( dfs(i+1,j), dfs(i,j-1) ) + 1;
	return ans;
}
void print_ans ( int i, int j ) {
	if ( i > j ) {
		return;
	}
	if ( i == j ) {
		printf ( "%c", s[i] );
		return;
	}
	if ( s[i] == s[j] ) {
		printf ( "%c", s[i] );
		print_ans ( i+1, j-1 );
		printf ( "%c", s[i] );
	}
	else if ( dp[i][j] == dp[i+1][j] + 1 ) {
		printf ( "%c", s[i] );
		print_ans ( i+1, j );
		printf ( "%c", s[i] );
	}
	else {
		printf ( "%c", s[j] );
		print_ans ( i, j-1 );
		printf ( "%c", s[j] );
	}
}
int main()
{
	while ( scanf ( "%s", s ) != EOF ) {
	//while ( fgets ( s, MAXN, stdin ) ) {
		//if ( strlen(s) == 1 ) continue;
		memset ( vis, 0, sizeof(vis) );
		printf ( "%d ", dfs(0,strlen(s)-1) );
		print_ans ( 0, strlen(s)-1 );
		printf ( "\n" );
	}
    return 0;
}
