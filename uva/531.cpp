/*************************************************************************
    > File Name: 531.cpp
    > Author: Coral_Peng
    > Mail: 313221234@qq.com 
    > Created Time: 2013年05月01日 星期三 14时50分58秒
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

vector < string > x, y;
int dp[128][128], b[128][128];
void LCS ( ) {
	int x_len = x.size ( );
	int y_len = y.size ( );
	memset ( dp, 0, sizeof(dp) );
	memset ( b, 0, sizeof(b) );
	int i, j;
	for ( i = 1; i <= x_len; ++i )
		for ( j = 1; j <= y_len; ++j )
			if ( x[i-1] == y[j-1] ) {
				dp[i][j] = dp[i-1][j-1] + 1;
				b[i][j] = 1;
			}
			//else dp[i][j] = max ( dp[i-1][j], dp[i][j-1] );
			else if ( dp[i-1][j] >= dp[i][j-1] ) {
				dp[i][j] = dp[i-1][j];
				b[i][j] = 2;
			}
			else {
				dp[i][j] = dp[i][j-1];
				b[i][j] = 3;
			}
}
int first;
void print_ans ( int i, int j ) {
	/*
	if ( i == 0 || j == 0 ) return;
	if ( x[i-1] == y[j-1] && dp[i][j] == dp[i-1][j-1] + 1 ) {
		print_ans ( i-1, j-1 );
		if ( first ) cout << x[i-1], first = 0;
		else cout << ' ' << x[i-1];
	}
	else if ( dp[i][j] == dp[i-1][j] ) print_ans ( i-1, j );
	else print_ans ( i, j-1 );
	*/
	if ( i == 0 || j == 0 ) return;
	if ( b[i][j] == 1 ) {
		print_ans ( i-1, j-1 );
		if ( first ) cout << x[i-1], first = 0;
		else cout << ' ' << x[i-1];
	}
	else if ( b[i][j] == 2 ) print_ans ( i-1, j );
	else print_ans ( i, j-1 );
}
int main()
{
	int flag = 1, cnt = 0;
	string s;
	while ( cin >> s ) {
		if ( s == "#" ) { 
			flag = !flag; 
			if ( cnt & 1 ) {
				LCS ( );
				//printf ( "ans=%d\n", dp[x.size()][y.size()] );
				first = 1;
				print_ans ( x.size(), y.size() );
				cout << "\n";
				x.clear ( ), y.clear ( );
			}
			cnt++; 
			continue; 
		}
		if ( flag ) x.push_back ( s );
		else y.push_back ( s );
	}
    return 0;
}
