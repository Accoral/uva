/*************************************************************************
    > File Name: 10324.cpp
    > Author: AC_coral
    > Mail: 313221234@qq.com 
    > Created Time: 2013年05月09日 星期四 22时06分11秒
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
const int MAXN = 1000010;
char s[MAXN];
int sum[MAXN];
int main()
{
	int n, i, j, t = 1;
	while ( fgets ( s, MAXN, stdin ) ) {
		//cout << "s" << s;
		if ( strcmp ( s, "\n" ) == 0 ) break;

		printf ( "Case %d:\n", t++ );
		int len = strlen ( s ) - 1;
		memset ( sum, 0, sizeof(sum) );
		sum[0] = s[0] - '0';
		for ( i = 1; i < len; ++i ) sum[i] = sum[i-1] + s[i] - '0';
		scanf ( "%d", &n );

		while ( n-- ) {
			scanf ( "%d%d", &i, &j );
			getchar ( );
			if ( i > j ) swap ( i, j );
			/*
			printf ( "=================\n" );
			printf ( "j=%d\ti=%d\tj-i=%d\n", j, i-1, j-i+1 );
			printf ( "%d\t%d\t%d\n", sum[j], sum[i-1], sum[j]-sum[i-1] );
			printf ( "=================\n" );
			*/
			int tmp = sum[j] - sum[i-1];
			if ( tmp == 0 || tmp == j-i+1 ) printf ( "Yes\n" );
			else printf ( "No\n" );
		}
	}
    return 0;
}
