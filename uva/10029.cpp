/*************************************************************************
    > File Name: 10029.cpp
    > Author: Coral_Peng
    > Mail: 313221234@qq.com 
    > Created Time: 2013年05月06日 星期一 15时23分31秒
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

const int MAXN = 25000 + 10;
map < string, int > dict[16+5];
int exist ( int len, string s, int step ) {
	map < string, int > :: iterator it;
	it = dict[len].find ( s );
	if ( it != dict[len].end() )
		step = max ( step, it->second + 1 );
	return step;
}
int main()
{
	string s, tmp;
	int current = 0;
	int ans = 0, i;

	while ( cin >> s ) {
		int len = s.length ( );
		int step = 1;
		if ( len > 1 ) {
			for ( i = 0; i < len; ++i ) {
				tmp = s;//delete
				if ( i == len-1 || tmp[i] >= tmp[i+1] ) {
					tmp.erase ( tmp.begin() + i );
					step = exist ( len-1, tmp, step );
				}
				tmp = s;//change
				while ( tmp[i] > 'a' ) {
					tmp[i]--;
					step = exist ( len, tmp, step );
				}
				tmp = s;//add
				tmp.insert ( tmp.begin() + i, s[i] );
				while ( tmp[i] > 'a' ) {
					tmp[i]--;
					step = exist ( len+1, tmp, step );
				}
			}
		}
		else { // len == 1;
			tmp = s;//change
			while ( tmp[0] > 'a' ) {
				tmp[0]--;
				step = exist ( len, tmp, step );
			}
		}
		ans = max ( ans, step );
		dict[len][s] = step;
		//cout << s << ' ' << step << endl;
	}
	printf ( "%d\n", ans );
    return 0;
}
