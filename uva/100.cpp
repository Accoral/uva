/*************************************************************************
    > File Name: 100.cpp
    > Author: Coral_Peng
    > Mail: 313221234@qq.com 
    > Created Time: 2013年05月08日 星期三 16时23分10秒
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
vector < int > v;
void init ( ) {
	int i, cnt;
	long long tmp;
	//int tmp;
	v.clear ( );
	v.push_back ( 1 ); v.push_back ( 2 );

	for ( i = 3; i <= 200000; ++i ) {
		cnt = 0;
		tmp = i;
		while ( 1 ) {
			if ( tmp&1 ) tmp = 3*tmp + 1;
			else tmp >>= 1;
			++cnt;
			if ( tmp < i ) {
				cnt += v[tmp-1];
				break;
			}
		}
		v.push_back ( cnt );
	}
}
int main()
{
	init ( );
	int i, j;
	while ( scanf ( "%d%d", &i, &j ) != EOF ) {
		printf ( "%d %d ", i, j );
		if ( i > j ) swap ( i, j );
		int ans = 0;
		for ( int k = i-1; k < j; ++k ) ans = max ( ans, v[k] );
		printf ( "%d\n", ans );
		//printf ( "%d\n", *max_element ( v.begin()+i-1, v.begin()+j ) );
	}
    return 0;
}
