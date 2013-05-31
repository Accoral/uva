/*************************************************************************
    > File Name: 10929.cpp
    > Author: AC_coral
    > Mail: 313221234@qq.com 
    > Created Time: 2013年05月26日 星期日 13时26分44秒
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
int main()
{
	char s[1024];
	int len, i, ans;
	while ( scanf ( "%s", s ) != EOF ) {
		if ( strcmp ( s, "0" ) == 0 ) break;
		len = strlen ( s );
		ans = 0;
		for ( i = 0; i < len; ++i ) {
			ans = ( ans * 10 + s[i] - '0' ) % 11;
		}
		if ( ans ) printf ( "%s is not a multiple of 11.\n", s );
		else printf ( "%s is a multiple of 11.\n", s );
	}
    return 0;
}
