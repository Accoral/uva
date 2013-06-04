/*************************************************************************
    > File Name: 11727.cpp
    > Author: AC_coral❤
    > Mail: 313221234@qq.com 
    > Created Time: 2013年06月04日 星期二 17时31分22秒
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
	int T, i, a[3], ncase = 1;
	scanf ( "%d", &T );
	while ( T-- ) {
		for ( i = 0; i < 3; ++i ) scanf ( "%d", a+i );
		sort ( a, a+i );
		printf ( "Case %d: %d\n", ncase++, a[1] );
	}
    return 0;
}
