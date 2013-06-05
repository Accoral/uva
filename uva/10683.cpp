/*************************************************************************
    > File Name: 10683.cpp
    > Author: AC_coral❤
    > Mail: 313221234@qq.com 
    > Created Time: 2013年06月05日 星期三 13时37分41秒
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
	char str[10];
	int h, m, s, c;
	double sum;
	while ( scanf ( "%s", str ) != EOF ) {
		h = (str[0]-'0')*10 + (str[1]-'0');
		m = (str[2]-'0')*10 + (str[3]-'0');
		s = (str[4]-'0')*10 + (str[5]-'0');
		c = (str[6]-'0')*10 + (str[7]-'0');
		sum = (h*3600+m*60+s)*100+c;
		sum = sum*1000/(24*36);
		printf ( "%07d\n", (int)sum );
	}
    return 0;
}
