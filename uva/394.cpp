/*************************************************************************
    > File Name: 394.cpp
    > Author: AC_coral❤
    > Mail: 313221234@qq.com 
    > Created Time: 2013年06月05日 星期三 12时42分46秒
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
struct Address {
	int c[11];
	int dim;
};
map < string, Address > mymap;
int main()
{
	int n, r, i, j, B, D, c[11], L[11], U[11], sz, ans, x[11];
	string s;
	while ( scanf ( "%d%d", &n, &r ) != EOF ) {
		mymap.clear ( );
		for ( i = 0; i < n; ++i ) {
			cin >> s;
			scanf ( "%d%d%d", &B, &sz, &D );
			mymap[s].dim = D;
			for ( j = 1; j <= D; ++j ) scanf ( "%d%d", L+j, U+j );
			mymap[s].c[D] = sz;
			for ( j = D-1; j > 0; --j ) mymap[s].c[j] = mymap[s].c[j+1]*(U[j+1]-L[j+1]+1);
			mymap[s].c[0] = B;
			for ( j = 1; j <= D; ++j ) mymap[s].c[0] -= mymap[s].c[j]*L[j];
		}
		for ( i = 0; i < r; ++i ) {
			cin >> s;
			sz = mymap[s].dim;
			ans = mymap[s].c[0];
			for ( j = 1; j <= sz; ++j ) {
				scanf ( "%d", x+j );
				ans += mymap[s].c[j]*x[j];
			}
			printf ( "%s[%d", s.c_str(), x[1] );
			for ( j = 2; j <= sz; ++j ) printf ( ", %d", x[j] );
			printf ( "] = %d\n", ans );
		}
	}
    return 0;
}
