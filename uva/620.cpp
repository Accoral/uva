/*************************************************************************
    > File Name: 620.cpp
    > Author: Coral_Peng
    > Mail: 313221234@qq.com 
    > Created Time: 2013年05月01日 星期三 19时16分54秒
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
char s[10240], ans[][100] = { "MUTANT", "SIMPLE", "FULLY-GROWN", "MUTAGENIC" };
int judge ( int start, int end ) {
	if ( end-start == 1 && s[start] == 'A' ) return 1;
	else if ( s[end-2] == 'A' && s[end-1] == 'B' && judge ( start, end-2 ) ) return 2;
	else if ( s[start] == 'B' && s[end-1] == 'A' && judge ( start+1, end-1 ) ) return 3;
	else return 0;
}
int main()
{
	int T;
	scanf ( "%d", &T );
	while ( T-- ) {
		scanf ( "%s", s );
		printf ( "%s\n", ans[judge(0,strlen(s))] );
	}
    return 0;
}
