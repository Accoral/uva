/*************************************************************************
    > File Name: 10404.cpp
    > Author: Coral_Peng
    > Mail: 313221234@qq.com 
    > Created Time: 2013年05月05日 星期日 10时23分07秒
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

int v[15], dp[1000001];
int n, m;
int main()
{
	int i, j, flag, x;
	while ( scanf ( "%d", &n ) != EOF ) {
		scanf ( "%d", &m );
		for ( i = 0; i < m; ++i ) scanf ( "%d", v+i );
		memset ( dp, 0, sizeof(dp) );
		for ( i = 1; i <= n; ++i ) 
			for ( j = 0; j < m; ++j ) if ( i >= v[j] && !dp[i-v[j]] ) {
					dp[i] = 1;
					break;
				}
		if ( dp[n] ) printf ( "Stan wins\n" );
		else printf ( "Ollie wins\n" );
	}
    return 0;
}
