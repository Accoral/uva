/*************************************************************************
    > File Name: 11547.cpp
    > Author: AC_coral❤
    > Mail: 313221234@qq.com 
    > Created Time: 2013年06月03日 星期一 22时23分20秒
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
	int T, x;
	scanf ( "%d", &T );
	while ( T-- ) {
		scanf ( "%d", &x );
		x = ( x*567/9+7492 ) * 235 / 47 - 498;
		if ( x < 0 ) x *= -1;
		printf ( "%d\n", x%100/10 );
	}
    return 0;
}
