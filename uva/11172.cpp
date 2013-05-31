/*************************************************************************
    > File Name: 11172.cpp
    > Author: AC_coral
    > Mail: 313221234@qq.com 
    > Created Time: 2013年05月09日 星期四 09时41分14秒
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

int main()
{
	int T, x, y;
	scanf ( "%d", &T );
	while ( T-- ) {
		scanf ( "%d%d", &x, &y );
		if ( x < y ) printf ( "<\n" );
		else if ( x > y ) printf ( ">\n" );
		else printf ( "=\n" );
	}
    return 0;
}
