/*************************************************************************
    > File Name: 562.cpp
    > Author: Coral_Peng
    > Mail: 313221234@qq.com 
    > Created Time: 2013年05月01日 星期三 22时19分33秒
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

int main()
{
	int T, a[128], sum, dp[128*500], n, i, j;
	scanf ( "%d", &T );
	while ( T-- ) {
		scanf ( "%d", &n );
		memset ( dp, 0, sizeof(dp) );
		for ( sum = i = 0; i < n; ++i ) {
			scanf ( "%d", a+i );
			sum += a[i];
		}
		dp[0] = 1;
		for ( i = 0; i < n; ++i )
			for ( j = sum; j >= a[i]; --j ) {
				if ( dp[j-a[i]] ) dp[j] = 1;
				for ( int k = 0; k <= sum; ++k ) printf ( "%d:%d ", k, dp[k] );
				printf ( "\n" );
			}
		for ( i = sum / 2; i >= 0; --i ) if ( dp[i] ) {
			printf ( "%d\n", sum - 2*i );
			break;
		}
	}
    return 0;
}
