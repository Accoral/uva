/*************************************************************************
    > File Name: 138.cpp
    > Author: AC_coral❤
    > Mail: 313221234@qq.com 
    > Created Time: 2013年06月01日 星期六 08时56分44秒
 ************************************************************************/

#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <climits>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <map>
#include <set>

using namespace std;
typedef unsigned int u32;
typedef long long i64;
typedef unsigned long long u64;
typedef vector<int> IV;
typedef vector<bool> BV;
typedef pair<int,int> II;
typedef vector<II> IIV;
#define For(t,v,c) for(t::const_iterator v=c.begin(); v!=c.end(); ++v)
const int INF = 0x7FFFFFFF;
int main()
{
	u64 i, j, cnt = 1;
	/*
	int ok;
	for ( i = 6; i <= 20961280; ++i ) {
		ok = 0;
		for ( j = i+1; j <= i+i/2; ++j ) {
			//printf ( "i=%llu\tj=%llu\n", i, j );
			if ( (i-1)*i < (j-i)*(i+1+j) )
				break;
			else if ( (i-1)*i == (j-i)*(i+1+j) )
				printf ( "%d: i=%llu\tj=%llu\n", cnt++,i, j ), printf ( "%llu\t%llu\n", (i-1)*i, (j-i)*(i+1+j) ), ok=1;
		}
		if ( ok ) i *= 5;
		//cout << i << endl;
	}
	*/
	u64 a, b, tmpa, tmpb, tmpi=0, tmpj=2;
	for ( a = 2, b = 3, cnt = 0; cnt < 10; ++cnt ) {

		i = a * b;
		j = tmpi + tmpj + i;

		printf ( "%10llu%10llu\n", i, j );
		int tmpa = a + b;
		int tmpb = 2*a + b;
		a = tmpa;
		b = tmpb;

		tmpi = i;
		tmpj = j;
	}
    return 0;
}
