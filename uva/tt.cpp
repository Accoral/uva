/*************************************************************************
    > File Name: tt.cpp
    > Author: AC_coral
    > Mail: 313221234@qq.com 
    > Created Time: 2013年05月29日 星期三 13时08分39秒
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
double xrandom ( ) {
	return (double)rand()/RAND_MAX;
}
int random(int m) {
	return (int)(xrandom()*(m-1)+0.5);
}
int main()
{
	srand ( time(NULL) );
	for ( int i = 2147480647; i != 2147483647; ++i ) printf ( "%d\n", i );
	printf ( "0\n" );
    return 0;
}
