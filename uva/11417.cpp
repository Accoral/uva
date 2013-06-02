/*************************************************************************
    > File Name: 11417.cpp
    > Author: AC_coral❤
    > Mail: 313221234@qq.com 
    > Created Time: 2013年06月02日 星期日 22时50分33秒
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
const int MAXN = 501;
int g[MAXN];
void prepare ( ) {
	int i, j;
	g[1] = 0;
	for ( i = 2; i < MAXN; ++i ) {
		g[i] = g[i-1];
		for ( j = 1; j < i; ++j )
			g[i] += __gcd ( j, i );
	}
}
int main()
{
	prepare ( );
	int x;
	while ( scanf ( "%d", &x ) != EOF && x ) {
		printf ( "%d\n", g[x] );
	}
    return 0;
}
