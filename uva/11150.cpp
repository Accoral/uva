/*************************************************************************
    > File Name: 11150.cpp
    > Author: AC_coral❤
    > Mail: 313221234@qq.com 
    > Created Time: 2013年06月03日 星期一 22时12分54秒
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
	int x, ans;
	while ( scanf ( "%d", &x ) != EOF ) {
		ans = x;
		while ( x/3 ) {
			ans += x / 3;
			x = x/3 + x%3;
		}
		if ( x%3 == 2 ) ++ans;
		printf ( "%d\n", ans );
	}
    return 0;
}
