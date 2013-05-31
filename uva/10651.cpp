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

int a[15];
int dfs ( int cnt ) {
	//printf ( "cnt=%d\n", cnt );
	//for ( int i = 0; i < 12; ++i ) printf ( "%d", a[i] ); printf ( "\n" );
	int ans = cnt;
	for ( int i = 0; i+2 < 12; ++i ) {
		if ( a[i] == 0 && a[i+1] == 1 && a[i+2] == 1 ) {
			a[i] = 1; a[i+1] = 0; a[i+2] = 0;
			ans = min ( ans, dfs ( cnt-1 ) );
			a[i] = 0; a[i+1] = 1; a[i+2] = 1;
		}
		if ( a[i] == 1 && a[i+1] == 1 && a[i+2] == 0 ) {
			a[i] = 0; a[i+1] = 0; a[i+2] = 1;
			ans = min ( ans, dfs ( cnt-1 ) );
			a[i] = 1; a[i+1] = 1; a[i+2] = 0;
		}
	}
	return ans;
}
int main()
{
	int i, n, cnt;
	char s[15];
	while ( scanf ( "%d", &n ) != EOF ) {
		while ( n-- ) {
			scanf ( "%s", s );
			for ( cnt = i = 0; i < 12; ++i ) {
				if ( s[i] == 'o' ) a[i] = 1, ++cnt;
				else a[i] = 0;
			}
			//for ( i = 0; i < 12; ++i ) printf("%d", a[i] ); printf ( "\n" );
			printf ( "%d\n", dfs(cnt) );
		}
	}
    return 0;
}
