/*************************************************************************
    > File Name: 483.cpp
    > Author: AC_coral❤
    > Mail: 313221234@qq.com 
    > Created Time: 2013年06月02日 星期日 22时22分30秒
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
	string str, s;
	int len, i;
	while ( getline ( cin, str ) ) {
		for ( len = str.length(), i = 0, s.clear(); i < len; ++i ) {
			if ( str[i] != ' ' ) s += str[i];
			else {
				reverse ( s.begin(), s.end() );
				cout << s;
				s.clear ( );
				cout << str[i];
			}
		}
		reverse ( s.begin(), s.end() );
		cout << s;
		cout << "\n";
	}
    return 0;
}
