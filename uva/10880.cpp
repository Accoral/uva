/*************************************************************************
    > File Name: 10880.cpp
    > Author: AC_coral
    > Mail: 313221234@qq.com 
    > Created Time: 2013年05月29日 星期三 13时44分38秒
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
vector < int > ans;
int main()
{
	int T, x, y, ncase = 1;
	scanf ( "%d", &T );
	while ( T-- ) {
		scanf ( "%d%d", &x, &y );
		printf ( "Case #%d:", ncase++ );
		if ( x == y ) printf ( " 0\n" );
		else {
			int diff = x - y;
			int sdiff = sqrt ( diff );
			ans.clear ( );
			for ( int i = 1; i <= sdiff; ++i ) {
				if ( diff % i ) continue;
				if ( i > y ) printf ( " %d", i );
				int odiv = diff/i;
				if ( i != odiv && odiv > y ) ans.push_back ( odiv );
			}
			for ( int i = ans.size()-1; i >= 0; --i ) printf ( " %d", ans[i] );
			printf ( "\n" );
		}
	}
    return 0;
}
