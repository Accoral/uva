/*************************************************************************
    > File Name: 10141.cpp
    > Author: AC_coral❤
    > Mail: 313221234@qq.com 
    > Created Time: 2013年06月04日 星期二 18时53分01秒
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
const double EPS = 1e-9;
int main()
{
	int n, p, i, j, x, ncase = 1, first = 1, best_x;
	double d, best_d;
	char s[88], name[88], best_name[88];
	while ( scanf ( "%d%d", &n, &p ) != EOF ) {
		if ( !n && !p ) break;
		if ( first ) first = 0;
		else puts ( "" );
		fgets ( s, 88, stdin );
		for ( i = 0; i < n; ++i ) fgets ( s, 88, stdin );
		for ( i = 0; i < p; ++i ) {
			fgets ( name, 88, stdin );
			scanf ( "%lf%d", &d, &x );
			if ( i == 0 ) {
				memcpy ( best_name, name, sizeof(name) );
				best_d = d;
				best_x = x;
			}
			else {
				if ( x > best_x ) {
					memcpy ( best_name, name, sizeof(name));
					best_d = d;
					best_x = x;
				}
				else if ( x == best_x ) {
					if ( best_d > d ) {
						best_d = d;
						memcpy ( best_name, name, sizeof(name) );
					}
				}
			}
			fgets ( s, 88, stdin );
			for ( j = 0; j < x; ++j ) fgets ( s, 88, stdin );
		}
		printf ( "RFP #%d\n", ncase++ );
		printf ( "%s", best_name );
		//printf ( "%lf %d\n", best_d, best_x );
	}
    return 0;
}
