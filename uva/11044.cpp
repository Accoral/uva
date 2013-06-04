/*************************************************************************
    > File Name: 11044.cpp
    > Author: AC_coral❤
    > Mail: 313221234@qq.com 
    > Created Time: 2013年06月03日 星期一 21时59分28秒
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
	int T, x, y;
	scanf ( "%d", &T );
	while ( T-- ) {
		scanf ( "%d%d", &x, &y );
		x -= 2; y -= 2;
		x = x/3 + (x%3?1:0);
		y = y/3 + (y%3?1:0);
		printf ( "%d\n", x*y );
	}
    return 0;
}
