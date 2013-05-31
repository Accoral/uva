/*************************************************************************
    > File Name: 105.cpp
    > Author: AC_coral
    > Mail: 313221234@qq.com 
    > Created Time: 2013年05月24日 星期五 13时40分00秒
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
int a[10010*2];
int main()
{
	int l, h, r, i, now;
	memset ( a, 0, sizeof(a) );
	while ( scanf ( "%d%d%d", &l, &h, &r ) != EOF ) {
		l *= 2; r *= 2;
		for ( i = l; i <= r; ++i ) a[i] = max ( a[i], h );
	}
	now = 0;
	for ( i = 0; i < 10010*2; ++i ) if ( a[i] != now ) {
		printf ( "%d %d", i/2, a[i] );
		now = a[i];
		break;
	}
	for ( ; i < 10010*2; ++i ) if ( a[i] != now ) {
		if ( a[i] > now ) printf ( " %d %d", i/2, a[i] );
		else if ( a[i] < now ) printf ( " %d %d", (i-1)/2, a[i] );
		now = a[i];
	}
	printf ( "\n" );
	//for ( i = 220; i < 231; ++i ) printf ( "%d ", a[i] ); printf ( "\n" );
    return 0;
}
