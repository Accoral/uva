/*************************************************************************
    > File Name: 119.cpp
    > Author: AC_coral
    > Mail: 313221234@qq.com 
    > Created Time: 2013年05月09日 星期四 15时10分29秒
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
map < string, int > ans;
vector < string > v;
int main()
{
	string s, give_name, receive_name;
	int i, num, money, t = 0, n, j;
	while ( scanf ( "%d", &n ) != EOF ) {
		if ( t++ ) printf ( "\n" );
		ans.clear ( ); v.clear ( );
		for ( i = 0; i < n; ++i ) {
			cin >> s;
			ans[s] = 0;
			v.push_back ( s );
		}
		for ( i = 0; i < n; ++i ) {
			cin >> give_name >> money >> num;
			if ( num == 0 ) continue;
			money /= num;
			for ( j = 0; j < num; ++j ) {
				cin >> receive_name;
				ans[give_name] -= money;
				ans[receive_name] += money;
			}
		}
		for ( i = 0; i < n; ++i ) printf ( "%s %d\n", v[i].c_str(), ans[v[i]] );
	}
    return 0;
}
