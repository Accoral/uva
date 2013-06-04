/*************************************************************************
    > File Name: 661.cpp
    > Author: AC_coral❤
    > Mail: 313221234@qq.com 
    > Created Time: 2013年06月04日 星期二 17时45分34秒
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
	int n, m, c, a[22], flag[22], i, x, sum, max_ans, ncase = 1;
	while ( scanf ( "%d%d%d", &n, &m, &c ) != EOF ) {
		if ( !n && !m && !c ) break;
		memset ( flag, 0, sizeof(flag) );
		for ( i = 1; i <= n; ++i ) scanf ( "%d", a+i );
		sum = max_ans = 0;
		for ( i = 0; i < m; ++i) {
			scanf ( "%d", &x );
			flag[x] = !flag[x];
			if ( flag[x] ) sum += a[x], max_ans = max ( max_ans, sum );
			else sum -= a[x];
		}
		printf ( "Sequence %d\n", ncase++ );
		if ( max_ans > c ) puts ( "Fuse was blown." );
		else printf ( "Fuse was not blown.\nMaximal power consumption was %d amperes.\n", max_ans );
		puts ( "" );
	}
    return 0;
}
