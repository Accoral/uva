/*************************************************************************
    > File Name: 417.cpp
    > Author: AC_coral
    > Mail: 313221234@qq.com 
    > Created Time: 2013年05月25日 星期六 16时05分58秒
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
map < string, int > mymap;
void init ( ) {
	queue < string > q;
	string s;
	int len, cnt = 1;
	for ( char i = 'a'; i <= 'z'; ++i ) {
		s.clear();
		s += i;
		q.push ( s );
	}
	while ( !q.empty ( ) ) {
		s.clear ( );
		s = q.front ( ); q.pop ( );
		mymap[s] = cnt++;
		if ( s.length ( ) == 6 ) break;
		//cout << s <<  '\t' << mymap[s] << endl;
		len = s.length ( );
		for ( char i = 'a'; i <= 'z'; ++i ) if ( s[len-1] < i ) {
			q.push ( s+i );
		}
	}
}
int main()
{
	init ( );
	string s;
	while ( cin >> s ) {
		printf ( "%d\n", mymap[s] );
	}
    return 0;
}
