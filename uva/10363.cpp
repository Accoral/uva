/*************************************************************************
    > File Name: 10363.cpp
    > Author: AC_coral❤
    > Mail: 313221234@qq.com 
    > Created Time: 2013年06月04日 星期二 22时02分27秒
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
char s[3][3];
int x, o;
int run ( ) {
	int res = 0;
	x = o = 0;
	for ( int i = 0; i < 3; ++i ) if ( s[i][0] == 'X' && s[i][0] == s[i][1] && s[i][1] == s[i][2] ) ++res, ++x;
	for ( int i = 0; i < 3; ++i ) if ( s[i][0] == 'O' && s[i][0] == s[i][1] && s[i][1] == s[i][2] ) ++res, ++o;
	for ( int j = 0; j < 3; ++j ) if ( s[0][j] == 'X' && s[0][j] == s[1][j] && s[1][j] == s[2][j] ) ++res, ++x;
	for ( int j = 0; j < 3; ++j ) if ( s[0][j] == 'O' && s[0][j] == s[1][j] && s[1][j] == s[2][j] ) ++res, ++o;
	if ( s[0][0] == 'X' && s[0][0] == s[1][1] && s[1][1] == s[2][2] ) ++res, ++x;
	if ( s[0][0] == 'O' && s[0][0] == s[1][1] && s[1][1] == s[2][2] ) ++res, ++o;
	if ( s[0][2] == 'X' && s[0][2] == s[1][1] && s[1][1] == s[2][0] ) ++res, ++x;
	if ( s[0][2] == 'O' && s[0][2] == s[1][1] && s[1][1] == s[2][0] ) ++res, ++o;
	return res;
}
int main()
{
	int cnt_x, cnt_o;
	int T, ok, i, j;
	scanf ( "%d", &T );
	while ( T-- ) {
		for ( i = 0; i < 3; ++i ) scanf ( "%s", s[i] );

		cnt_x = cnt_o = 0; ok = 1;
		for ( i = 0; i < 3; ++i )
			for ( j = 0; j < 3; ++j )
				if ( s[i][j] == 'X' ) ++cnt_x;
				else if ( s[i][j] == 'O' ) ++cnt_o;
				else if ( s[i][j] != '.' ) ok = 0;
		//printf ( "x=%d o=%d\n", cnt_x, cnt_o );
		if ( ok ) {
			if ( run() == 2 && cnt_x == 5 && x==2 && o == 0 && (cnt_x-cnt_o==1||cnt_x-cnt_o==0) ) ok = 1;
			else if ( run() == 0 && (cnt_x-cnt_o==1||cnt_x-cnt_o==0) ) ok = 1;
			else if ( run() == 1 && x == 1 && cnt_x-cnt_o == 1 ) ok = 1;
			else if ( run() == 1 && o == 1 && cnt_x-cnt_o == 0 ) ok = 1;
			else ok = 0;
		}
		if ( ok ) puts ( "yes" );
		else puts ( "no" );
	}
    return 0;
}
