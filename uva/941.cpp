/*************************************************************************
    > File Name: 941.cpp
    > Author: AC_coral❤
    > Mail: 313221234@qq.com 
    > Created Time: 2013年06月05日 星期三 15时00分51秒
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
	string s;
	int i, j, k, T, len, used[21];
	i64 n, f[21]={1,1};
	for ( i = 2; i <= 20; ++i ) f[i] = f[i-1]*i;
	scanf ( "%d", &T );
	while ( T-- ) {
		cin >> s >> n;
		sort ( s.begin(), s.end() );
		len = s.length ( );
		++n;
		memset ( used, 0, sizeof(used) );
		for ( i = 0; i < len; ++i ) {
			for ( j = 0; j <= len; ++j ) if ( f[len-i-1]*j >= n ) break;
			--j;
			n -= f[len-i-1]*j;
			for ( k = 0; k < len; ++k ) if ( !used[k] ) {
				if ( j == 0 ) {
					printf ( "%c", s[k] );
					used[k] = 1;
					break;
				}
				--j;
			}
		}
		puts ( "" );
	}
    return 0;
}
