/*************************************************************************
    > File Name: 10783.cpp
    > Author: AC_coral
    > Mail: 313221234@qq.com 
    > Created Time: 2013年05月29日 星期三 09时08分25秒
 ************************************************************************/

#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <climits>
#include <sstream>
#include <fstream>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <map>
#include <set>

using namespace std;
const int INF = 0x7FFFFFFF;
int a, b;
int solve ( ) {
	a = a&1 ? a-1 : a;
	b = b&1 ? b+1 : b;
	//printf ( "a=%d b=%d\n", a,b );
	//printf ( "%d\n", (b*(b+1)-a*(a+1)-(b-a))/4 );
	return (b*(b+1)-a*(a+1)-(b-a))/4;
}
int main()
{
	int T, ncase = 1;
	scanf ( "%d", &T );
	while ( T-- ) {
		scanf ( "%d%d", &a, &b );
		printf ( "Case %d: %d\n", ncase++, solve() );
	}
    return 0;
}
