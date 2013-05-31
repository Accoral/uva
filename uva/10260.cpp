/*************************************************************************
    > File Name: 10260.cpp
    > Author: AC_coral
    > Mail: 313221234@qq.com 
    > Created Time: 2013年05月25日 星期六 15时22分07秒
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
map < char, int > m;
int main()
{
	m['B'] = m['F'] = m['P'] = m['V'] = 1;
	m['C'] = m['G'] = m['J'] = m['K'] = m['Q'] = m['S'] = m['X'] = m['Z'] = 2;
	m['D'] = m['T'] = 3;
	m['L'] = 4;
	m['M'] = m['N'] = 5;
	m['R'] = 6;
	char s[25];
	int len, i, pre;
	while ( scanf ( "%s", s ) != EOF ) {
		len = strlen ( s );
		pre = 0;
		for ( i = 0; i < len; ++i ) {
			if ( s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U' || s[i] == 'H' || s[i] == 'W' || s[i] == 'Y' ) {
				pre = 0;
				continue;
			}
			else {
				if ( pre != m[s[i]] ) {
					printf ( "%d", m[s[i]] );
					pre = m[s[i]];
				}
			}	
		}
		printf ( "\n" );
	}
    return 0;
}
