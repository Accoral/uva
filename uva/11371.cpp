/*************************************************************************
    > File Name: 11371.cpp
    > Author: AC_coral
    > Mail: 313221234@qq.com 
    > Created Time: 2013年05月28日 星期二 19时09分17秒
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
typedef unsigned long long u64;
int main()
{
	char lo[12], hi[12];
	while ( scanf ( "%s", lo ) != EOF ) {
		strcpy ( hi, lo );
		int len = strlen ( lo );
		sort ( lo, lo + len );
		sort ( hi, hi + len, greater<int>() );
		int idx = strspn ( lo, "0" );
		if ( idx < len ) swap ( lo[0], lo[idx] );

		u64 n1, n2;
		sscanf ( hi, "%llu", &n1 );
		sscanf ( lo, "%llu", &n2 );
		printf ( "%llu - %llu = %llu = 9 * %llu\n", n1, n2, n1-n2, (n1-n2)/9 );
	}
    return 0;
}
