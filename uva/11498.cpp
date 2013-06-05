/*************************************************************************
    > File Name: 11498.cpp
    > Author: AC_coral❤
    > Mail: 313221234@qq.com 
    > Created Time: 2013年06月05日 星期三 14时52分22秒
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
const char *s[] = { "divisa", "SO", "NO", "SE", "NE" };
int main()
{
	int T, i, X, Y, x, y;
	while ( scanf ( "%d", &T ) != EOF && T ) {
		scanf ( "%d%d", &X, &Y );
		for ( i = 0; i < T; ++i ) {
			scanf ( "%d%d", &x, &y );
			if ( x == X || y == Y ) puts ( s[0] );
			else if ( x < X && y < Y ) puts ( s[1] );
			else if ( x < X && y > Y ) puts ( s[2] );
			else if ( x > X && y < Y ) puts ( s[3] );
			else if ( x > X && y > Y ) puts ( s[4] );
		}
	}
    return 0;
}
