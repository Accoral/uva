/*************************************************************************
    > File Name: 10585.cpp
    > Author: AC_coral
    > Mail: 313221234@qq.com 
    > Created Time: 2013年05月24日 星期五 16时10分04秒
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
int x[10010], y[10010];
map < pair<int,int>, int > mymap;
int sumx, sumy, n;
int judge ( ) {
	sumx <<= 1; sumy <<= 1;
	if ( sumx % n || sumy % n ) return 0;
	for ( int i = 0; i < n; ++i ) {
		if ( mymap.count (make_pair(sumx/n-x[i],sumy/n-y[i])) == 0 )
			return 0;
	}
	return 1;
}
int main()
{
	int T, i;
	scanf ( "%d", &T );
	while ( T-- ) {
		scanf ( "%d", &n );
		mymap.clear ( );
		for ( sumx = sumy = i = 0; i < n; ++i ) {
			scanf ( "%d%d", x+i, y+i );
			sumx += x[i]; sumy += y[i];
			mymap[make_pair(x[i],y[i])]=1;
		}
		//cout << sumx << ' ' << sumy << endl;
		if ( judge() ) printf( "yes\n" );
		else printf ( "no\n" );
	}
    return 0;
}
