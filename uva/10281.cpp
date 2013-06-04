/*************************************************************************
    > File Name: 10281.cpp
    > Author: AC_coral❤
    > Mail: 313221234@qq.com 
    > Created Time: 2013年06月04日 星期二 20时07分38秒
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
	char str[100];
	int h, m, s, time, pre_time, first = 1, n;
	double speed = 0, dis = 0, pre_speed = 0;
	while ( fgets ( str, 100, stdin ) ) {
		n = sscanf ( str, "%d:%d:%d %lf", &h, &m, &s, &speed );
		time = h*3600+m*60+s;
		dis += (time-pre_time)*pre_speed;
		pre_time = time;
		if ( n == 3 ) printf ( "%02d:%02d:%02d %.2lf km\n", h, m, s, dis/3600 );
		else pre_speed = speed;
	}
    return 0;
}
