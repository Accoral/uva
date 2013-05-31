/*************************************************************************
    > File Name: 12289.cpp
    > Author: AC_coral
    > Mail: 313221234@qq.com 
    > Created Time: 2013年05月09日 星期四 09时53分08秒
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
const char *one = "one";
void judge ( char *s ) {
	if ( strlen ( s ) == 5 ) {
		printf ( "3\n" );
		return;
	}
	int cnt = 0, i;
	for ( i = 0; i < 3; ++i ) if ( s[i] == one[i] ) ++cnt;
	if ( cnt == 2 || cnt == 3 ) {
		printf ( "1\n" );
		return;
	}
	printf ( "2\n" );
}
int main()
{
	int n;
	char s[8];
	while ( scanf ( "%d", &n ) != EOF ) {
		while ( n-- ) {
			scanf ( "%s", s );
			judge ( s );
		}
	}
    return 0;
}
