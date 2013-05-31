/*************************************************************************
    > File Name: 10651.cpp
    > Author: Coral_Peng
    > Mail: 313221234@qq.com 
    > Created Time: 2013年05月02日 星期四 13时08分29秒
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
   　　　　x&(1<<i)表示取出第i位；

   　　　　x&(~(1<<i))表示把第i位变成0；

   　　　　x|(1<<i)表示把第i位变成1；
*/
int dp[4100], vis[4100];
int dfs ( int x ) {
	int &ans = dp[x];
	if ( vis[x] ) return ans;
	vis[x] = 1;
	ans = 0;
	int t, i;
	for ( i = 0; i < 12; ++i ) if ( x&(1<<i) ) ++ans;
	for ( i = 0; i+2 < 12; ++i ) {
		if ( !(x&(1<<i)) && (x&(1<<(i+1))) && (x&(1<<(i+2))) ) {
			t = x;
			t |= (1<<i);
			t &= ~(1<<(i+1));
			t &= ~(1<<(i+2));
			ans = min ( ans, dfs(t) );
		}
		if ( (x&(1<<i)) && (x&(1<<(i+1))) && !(x&(1<<(i+2))) ) {
			t = x;
			t &= ~(1<<i);
			t &= ~(1<<(i+1));
			t |= (1<<(i+2));
			ans = min ( ans, dfs(t) );
		}
	}
	return ans;
}
int main()
{
	int i, n, x;
	char s[15];
	while ( scanf ( "%d", &n ) != EOF ) {
		while ( n-- ) {
			scanf ( "%s", s );
			for ( x = i = 0; i < 12; ++i ) if ( s[i] == 'o' )
				x ^= (1<<i);
			memset ( vis, 0, sizeof(vis) );
			printf ( "%d\n", dfs(x) );
		}
	}
    return 0;
}
