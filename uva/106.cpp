/*************************************************************************
    > File Name: 106.cpp
    > Author: AC_coral❤
    > Mail: 313221234@qq.com 
    > Created Time: 2013年06月01日 星期六 17时51分59秒
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
char flag[1000002];
int main()
{
	int sn, n, r, s, x, y, z, k, up, ans, total, cnt=0;
	while ( scanf ( "%d", &n ) != EOF ) {
		cnt = 0;
		ans = total = 0;
		memset ( flag, 0, sizeof(flag) );
		sn = sqrt ( n );
		if ( sn*sn < n ) ++sn;
		for ( r = 1; r <= sn; ++r ) {
			up = min ( n-r*r, r-1 );
			for ( s = 1; s <= up; ++s ) {
				x = r*r - s*s;
				y = 2*r*s;
				z = r*r + s*s;
				if ( z <= n ) {
					if ( __gcd(x,y) == 1 ) {
						++ans;
						for ( k = 1; k*z <= n; ++k ) flag[k*x]=flag[k*y]=flag[k*z]=1;
					}
				}
			}
		}
		for ( k = 1; k <= n; ++k ) if ( flag[k] == 0 ) ++total;
		printf ( "%d %d\n", ans, total );
	}
    return 0;
}
