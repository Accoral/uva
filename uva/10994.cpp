/*************************************************************************
    > File Name: 10994.cpp
    > Author: AC_coral
    > Mail: 313221234@qq.com 
    > Created Time: 2013年05月10日 星期五 09时43分17秒
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
const int INF = 0x7fffffff;
long long sum ( long long n ) {
	long long ans = 0;
	while ( n ) {
		ans += (n/10) * 45;
		for ( long long i = (n/10) * 10 + 1; i <= n; ++i ) ans += i % 10;
		n /= 10;
	}
	return ans;
}
int main()
{
	int i, j, p, q;
	while ( scanf ( "%d%d", &p, &q ) != EOF && p >= 0 && q >= 0 ) {
		printf ( "%lld\n", sum(q) - sum(p-1) );
	}
    return 0;
}
