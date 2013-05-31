/*************************************************************************
    > File Name: 10222.cpp
    > Author: AC_coral
    > Mail: 313221234@qq.com 
    > Created Time: 2013年05月25日 星期六 15时36分50秒
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
const char *str = "`1234567890-=+qwertyuiop[]\\asdfghjkl;'zxcvbnm,./";
int main()
{
	char c;
	int i;
	while ( ( c = getchar ( ) ) != EOF ) {
		c = tolower ( c );
		for ( i = 0; str[i] && c != str[i]; ++i );
		if ( str[i] ) putchar ( str[i-2] );
		else putchar ( c );
	}
    return 0;
}
