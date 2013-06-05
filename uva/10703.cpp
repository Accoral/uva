/*************************************************************************
    > File Name: 10703.cpp
    > Author: AC_coral❤
    > Mail: 313221234@qq.com 
    > Created Time: 2013年06月05日 星期三 14时33分32秒
 ************************************************************************/

#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <climits>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <map>
#include <set>

using namespace std;
typedef unsigned int u32;
typedef long long i64;
typedef unsigned long long u64;
typedef vector<int> IV;
typedef vector<bool> BV;
typedef pair<int,int> II;
typedef vector<II> IIV;
#define For(t,v,c) for(t::const_iterator v=c.begin(); v!=c.end(); ++v)
const int INF = 0x7FFFFFFF;
int main()
{
	int w, h, n, a[505][505], i, j, ans, x1, y1, x2, y2;
	while ( scanf ( "%d%d%d", &w, &h, &n ) != EOF ) {
		if ( !w && !h && !n ) break;
		memset ( a, 0, sizeof(a) );
		while ( n-- ) {
			scanf ( "%d%d%d%d", &x1, &y1, &x2, &y2 );
			if ( x1 > x2 ) swap ( x1, x2 );
			if ( y1 > y2 ) swap ( y1, y2 );
			for ( i = x1; i <= x2; ++i )
				for ( j = y1; j <= y2; ++j )
					if ( !a[i][j] ) a[i][j] = 1;
		}
		ans = 0;
		for ( i = 1; i <= w; ++i )
			for ( j = 1; j <= h; ++j ) if ( !a[i][j] ) ++ans;
		//printf ( "ans=%d\n", ans );
		if ( !ans ) printf ( "There is no empty spots.\n" );
		else if ( ans == 1 ) printf ( "There is one empty spot.\n" );
		else printf ( "There are %d empty spots.\n", ans );
	}
    return 0;
}
