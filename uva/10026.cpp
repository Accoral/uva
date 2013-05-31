/*************************************************************************
    > File Name: 10026.cpp
    > Author: AC_coral
    > Mail: 313221234@qq.com 
    > Created Time: 2013年05月09日 星期四 14时17分02秒
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
map < string, int > mymap;
map < string, int > :: iterator it;
int main()
{
	int T, total;
	string s;
	cin >> T;
	getline ( cin, s );
	getline ( cin, s );
	while ( T-- ) {
		mymap.clear ( );
		total = 0;
		while ( getline ( cin, s ) ) {
			if ( s == "" ) break;
			mymap[s]++;
			total++;
		}
		//cout << total << endl;
		for ( it = mymap.begin(); it != mymap.end(); ++it )
			//printf ( "%s %d\n", it->first.c_str(), it->second );
			printf ( "%s %.4lf\n", it->first.c_str(), it->second * 100.0 / total );
		if ( T ) printf ( "\n" );
	}
    return 0;
}
