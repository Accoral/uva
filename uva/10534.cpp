/*************************************************************************
    > File Name: 10534.cpp
    > Author: Coral_Peng
    > Mail: 313221234@qq.com 
    > Created Time: 2013年05月02日 星期四 08时18分07秒
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
const int MAXN = 10010;
int a[MAXN], n, dp1[MAXN], dp2[MAXN];
vector < int > v;
int main()
{
	int i, ans, j, pos;
	while ( scanf ( "%d", &n ) != EOF ) {
		for ( i = 0; i < n; ++i ) scanf ( "%d", a+i );

		v.clear ( ); v.push_back ( a[0] ); dp1[0] = 1;
		for ( i = 1; i < n; ++i ) {
			if ( v[v.size()-1] < a[i] ) v.push_back ( a[i] );
			else {
				pos = lower_bound ( v.begin(), v.end(), a[i] ) - v.begin();
				v[pos] = a[i];
			}
			dp1[i] = v.size();
		}

		v.clear ( ); v.push_back ( a[n-1] ); dp2[n-1] = 1;
		for ( i = n-2; i >= 0; --i ) {
			if ( v[v.size()-1] < a[i] ) v.push_back ( a[i] );
			else {
				pos = lower_bound ( v.begin(), v.end(), a[i] ) - v.begin();
				v[pos] = a[i];
			}
			dp2[i] = v.size();
		}

		ans = 0;
		for ( i = 0; i < n; ++i ) {
			//printf ( "%d	%d\n", dp1[i], dp2[i] );
			ans = max ( ans, min(dp1[i], dp2[i]) );
		}
		printf ( "%d\n", 2*ans-1 );
	}
    return 0;
}
