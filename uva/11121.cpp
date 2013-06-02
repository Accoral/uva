/*************************************************************************
    > File Name: 11121.cpp
    > Author: AC_coral❤
    > Mail: 313221234@qq.com 
    > Created Time: 2013年06月01日 星期六 20时31分22秒
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
	int x, T, tmp, ncase = 1;
	scanf ( "%d", &T );
	while ( T-- ) {
		scanf ( "%d", &x );
		string s;
		if ( !x ) s += '0';
		while ( x ) {
			tmp = (x%2+2)%2;
			s += tmp + '0';
			x = (x-tmp) / (-2);
		}
		printf ( "Case #%d: ", ncase++ );
		for ( int i = s.length()-1; i >= 0; --i ) printf ( "%c", s[i] );
		printf ( "\n" );
	}
    return 0;
}
