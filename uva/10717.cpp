/*************************************************************************
    > File Name: 10717.cpp
    > Author: AC_coral❤
    > Mail: 313221234@qq.com 
    > Created Time: 2013年06月02日 星期日 11时12分12秒
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
int lcm ( int x, int y ) {
	return x/__gcd(x,y)*y;
}
int main()
{
	int n, t, d, a[55], i, j, k, l, tmp;
	while ( scanf ( "%d%d", &n, &t ) != EOF ) {
		if ( !n && !t ) break;
		for ( i = 0; i < n; ++i ) scanf ( "%d", a + i );
		while ( t-- ) {
			scanf ( "%d", &d );
			int minn = INF, maxn = -INF;
			for ( i = 0; i < n; ++i )
				for ( j = i+1; j < n; ++j )
					for ( k = j+1; k < n; ++k )
						for ( l = k+1; l < n; ++l ) {
							tmp = lcm ( a[i], lcm(a[j], lcm(a[k], a[l])) );
							//cout << tmp << endl;
							maxn = max ( maxn, d/tmp*tmp);
							minn = min ( minn, (d/tmp+(d%tmp?1:0))*tmp );
						}
			printf ( "%d %d\n", maxn, minn );
		}
	}
    return 0;
}
