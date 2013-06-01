/*************************************************************************
    > File Name: 128.cpp
    > Author: AC_coral❤
    > Mail: 313221234@qq.com 
    > Created Time: 2013年06月01日 星期六 13时22分03秒
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
const int MOD = 34943;
int main()
{
	char s[1024], ans[5];
	int i, len, x;
	u64 sum;
	while ( fgets ( s, 1024, stdin) ) {
		if ( strcmp ( s, "#\n" ) == 0 ) break;
		len = strlen ( s ) - 1;
		sum = 0;
		for ( i = 0; i < len; ++i ) sum = ((sum<<8) + s[i]) % MOD;
		sum = (sum<<16)%MOD;
		sum = (MOD - sum)%MOD;
		sprintf ( ans, "%04X", sum );
		printf ( "%c%c %c%c\n", ans[0], ans[1], ans[2], ans[3] );
	}
    return 0;
}
