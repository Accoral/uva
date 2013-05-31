/*************************************************************************
    > File Name: 846.cpp
    > Author: AC_coral
    > Mail: 313221234@qq.com 
    > Created Time: 2013年05月26日 星期日 17时38分52秒
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
/*
   走n步能达到的最远距离
   if n is odd  (n/2)^2+n/2
   else         ((1+n)/2)^2
   */
int main()
{
	int T, x, y;
	scanf ( "%d", &T );
	while ( T-- ) {
		scanf ( "%d%d", &x, &y );
		int dist = y - x;
		if ( dist == 0 ) {
			printf ( "0\n" );
			continue;
		}
		int ans = sqrt ( dist );
		if ( ans*ans == dist ) ans = ans*2 - 1;
		else ans =  floor(sqrt(4.0*dist+1)-1 - 1e-9) + 1;
		//else ans = floor ( sqrt(4.0*dist+1) - 1 ) + 1; //WA P82 为了避免误差
		//cout << sqrt ( 4.0 * dist + 1 ) - 1 << ' ' << ans << endl;
		/*
		else if ( ans*ans + ans < dist ) ans = ans*2 + 1;
		else ans = ans*2;
		*/
		printf ( "%d\n", ans );
	}
    return 0;
}
