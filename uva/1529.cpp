/*************************************************************************
    > File Name: 1529.cpp
    > Author: Coral_Peng
    > Mail: 313221234@qq.com 
    > Created Time: 2013年05月08日 星期三 19时35分54秒
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
map < int, int > mymap;
int main()
{
	int h1, m1, h2, m2, i;
	/*
	for ( i = 1; i <= 11; ++i ) {//i:60/11*i
		double tmp=i*60+60.0/11*i;
		printf ( "%f  %d  %d\n", tmp, (int)floor(tmp), (int)ceil(tmp) );
	}
	*/
	printf ( "Program 3 by team X\n" );
	printf ( "Initial time  Final time  Passes\n" );
	while ( scanf ( "%d%d%d%d", &h1, &m1, &h2, &m2 ) != EOF ) {
		int i = h1*60+m1;
		int j = h2*60+m2;
		int cnt = 0;
		mymap.clear ( );
		while ( 1 ) {
			i = ( i + 1 ) % 780;
			//printf ( "%d ", i );
			mymap[i] = 1;
			if ( i == j ) break;
		}
		for ( i = 1; i <= 11; ++i ) {//i:60/11*i
			double tmp=i*60+60.0/11*i;
			if( mymap[(int)floor(tmp)] && mymap[(int)ceil(tmp)] ) {
				//printf ( "%f  %d  %d\n", tmp, (int)floor(tmp), (int)ceil(tmp) );
				++cnt;
			}
		}
		printf ( "       %02d:%02d       %02d:%02d%8d\n", h1,m1,h2,m2,cnt );
	}
	printf ( "End of program 3 by team X\n" );
    return 0;
}
