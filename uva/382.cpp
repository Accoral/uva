/*************************************************************************
    > File Name: 382.cpp
    > Author: AC_coral
    > Mail: 313221234@qq.com 
    > Created Time: 2013年05月29日 星期三 14时08分50秒
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
	int n, i;
	printf ( "PERFECTION OUTPUT\n" );
	while ( scanf ( "%d", &n ) != EOF && n ) {
		int sn = sqrt ( n ), sum = 0, odiv;
		for ( i = 1; i <= sn; ++i ) {
			if ( n % i ) continue;
			if ( i < n ) sum += i;
			odiv = n/i;
			if ( i != odiv && odiv < n ) sum += odiv;
		}
		printf ( "%5d  ", n );
		if ( n == sum ) printf ( "PERFECT\n" );
		else if ( n < sum ) printf ( "ABUNDANT\n" );
		else printf ( "DEFICIENT\n" );
		//printf ( "n=%d sum=%d\n", n, sum );
	}
	printf ( "END OF OUTPUT\n" );
    return 0;
}
