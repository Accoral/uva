/*************************************************************************
    > File Name: 141.cpp
    > Author: AC_coral
    > Mail: 313221234@qq.com 
    > Created Time: 2013年05月25日 星期六 13时01分50秒
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
map < vector<int>, int > mymap;
vector < int > v1, v2, v3, v4;
int a[55][55];
int main()
{
	char op[5];
	int i, n, x, y, j, k, move, ok;
	while ( scanf ( "%d", &n ) != EOF && n ) {
		memset ( a, 0, sizeof(a) );
		mymap.clear ( );
		ok = 0;
		for ( k = 0; k < 2*n; ++k ) {
			scanf ( "%d%d%s", &x, &y, op );
			if ( op[0] == '+' ) a[x][y] = 1;
			else a[x][y] = 0;

			if ( !ok ) {
				v1.clear(); v1.reserve(2*n);
				for ( i = 1; i <= n; ++i ) for ( j = 1; j <= n; ++j ) v1.push_back ( a[i][j] );

				v2.clear(); v2.reserve(2*n);
				for ( i = n; i >= 1; --i ) for ( j = 1; j <= n; ++j ) v2.push_back ( a[j][i] );

				v3.clear(); v3.reserve(2*n);
				for ( i = 1; i <= n; ++i ) for ( j = n; j >= 1; --j ) v3.push_back ( a[j][i] );

				v4.clear(); v4.reserve(2*n);
				for ( i = n; i >= 1; --i ) for ( j = n; j >= 1; --j ) v4.push_back ( a[i][j] );

				if ( mymap.count(v1) || mymap.count(v2) || mymap.count(v3) || mymap.count(v4) ) {
					ok = 1;
					move = k;
				}
				mymap[v1] = mymap[v2] = mymap[v3] = mymap[v4] = 1;
			}
		}
		if ( ok ) printf ( "Player %d wins on move %d\n", move%2 ? 1 : 2, move + 1 );
		else printf ( "Draw\n" );
	}
    return 0;
}
