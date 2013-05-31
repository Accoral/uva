/*************************************************************************
    > File Name: 296.cpp
    > Author: AC_coral
    > Mail: 313221234@qq.com 
    > Created Time: 2013年05月26日 星期日 14时34分37秒
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
struct {
	char s[5];
	int x, y;
}num[15];
int main()
{
	int T, n, i, j, k, x[4], cntx, cnty;
	scanf ( "%d", &T );
	while ( T-- ) {
		scanf ( "%d", &n );
		for ( i = 0; i < n; ++i ) scanf ( "%s %d/%d", num[i].s, &num[i].x, &num[i].y );
		//for ( i = 0; i < n; ++i ) printf ( "%s %d %d\n", num[i].s, num[i].x, num[i].y ); printf ( "\n" );
		int cnt = 0, ok, go = 1, ans, vis1[4], vis2[4];
		for ( x[0] = 0; go && x[0] < 10; ++x[0] )
			for ( x[1] = 0; go && x[1] < 10; ++x[1] )
				for ( x[2] = 0; go && x[2] < 10; ++x[2] )
					for ( x[3] = 0; go && x[3] < 10; ++x[3] ) {
						ok = 1;
						for ( i = 0; go && i < n; ++i ) {
							cntx = cnty = 0;
							for ( j = 0; j < 4; ++j ) vis1[j] = vis2[j] = 0;
							for ( j = 0; j < 4; ++j ) if ( x[j] == num[i].s[j]-'0' ) {
								++cntx;
								vis1[j] = vis2[j] = 1;
							}
							for ( j = 0; j < 4; ++j )
								for ( k = 0; k < 4; ++k )
									if ( num[i].s[j]-'0' == x[k] && !vis1[j] && !vis2[k] ) {
										++cnty;
										vis1[j] = 1;
										vis2[k] = 1;
									}
							if ( cntx != num[i].x || cnty != num[i].y ) {
								ok = 0;
								break;
							}
						}
						if ( ok ) { 
							for ( ans = i = 0; i < 4; ++i ) ans = ans*10 + x[i];
							++cnt;
							if ( cnt > 1 ) go = 0;
						}
					}
		/*
		int cnt = 0, ok, ans, vis1[4], vis2[4];
		for ( int m = 0; m <= 9999; ++m ) {
			x[0]=m/1000; x[1]=(m/100)%10; x[2]=(m/10)%10; x[3]=m%10;
			ok = 1;
			for ( i = 0; i < n; ++i ) {
				cntx = cnty = 0;
				//for ( j = 0; j < 4; ++j ) vis1[j] = vis2[j] = 0;
				vis1[0] = vis1[1] = vis1[2] = vis1[3] = 0;
				vis2[0] = vis2[1] = vis2[2] = vis2[3] = 0;
				for ( j = 0; j < 4; ++j ) if ( x[j] == num[i].s[j]-'0' ) {
					++cntx;
					vis1[j] = vis2[j] = 1;
				}
				for ( j = 0; j < 4; ++j )
					for ( k = 0; k < 4; ++k )
						if ( num[i].s[j]-'0' == x[k] && !vis1[j] && !vis2[k] ) {
							++cnty;
							vis1[j] = vis2[k] = 1;
						}
				if ( cntx != num[i].x || cnty != num[i].y ) {
					ok = 0;
					break;
				}
			}
			if ( ok ) { 
				ans = m;
				++cnt;
				if ( cnt > 1 ) break;
			}
		}
		*/
		if ( cnt == 1 ) printf ( "%04d\n", ans );
		else if ( !cnt ) printf ( "impossible\n" );
		else printf ( "indeterminate\n" );
	}
    return 0;
}
