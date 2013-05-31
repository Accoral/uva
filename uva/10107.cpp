/*************************************************************************
    > File Name: 10107.cpp
    > Author: AC_coral
    > Mail: 313221234@qq.com 
    > Created Time: 2013年05月24日 星期五 12时41分26秒
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
vector < int > v;
int main()
{
	int x, len;
	v.reserve ( 10010 );
	while ( scanf ( "%d", &x ) != EOF ) {
		v.push_back ( x );
		len = v.size ( );
		sort ( v.begin ( ), v.end ( ) );
		if ( len & 1 ) printf ( "%d\n", v[len/2] );
		else printf ( "%d\n", (v[len/2-1]+v[len/2])/2 );
	}
    return 0;
}
