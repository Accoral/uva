/*************************************************************************
    > File Name: 10673.cpp
    > Author: AC_coral❤
    > Mail: 313221234@qq.com 
    > Created Time: 2013年06月01日 星期六 19时24分16秒
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
template<typename T>
void ext_euclid(T a, T b, T &x, T &y, T &g) {
    x = 0; y = 1; g = b;
    T m, n, q, r;
    for (T u=1, v=0; a != 0; g=a, a=r) {
        q = g / a; r = g % a;
        m = x-u*q; n = y-v*q;
        x=u; y=v; u=m; v=n;
    }
}
int main()
{
	int T, X, K, x, y, fl, ce, d;
	scanf ( "%d", &T );
	while ( T-- ) {
		scanf ( "%d%d", &X, &K );
		fl = floor((double)X/K);
		ce = ceil((double)X/K);
		ext_euclid ( fl, ce, x, y, d );
		printf ( "%d %d\n", x*X/d, y*X/d );
	}
    return 0;
}
