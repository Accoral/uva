#include <stdio.h>
#include <math.h>
#include <string>
#include <iostream>
using namespace std;
int t, n, x;
int f ( int i ) {
	int ans = 0;
	while ( i ) {
		i /= 10;
		++ans;
	}
	return ans;
}
string ans;
void init ( ) {
	for ( int i = 1; i < 100000; ++i ) {
		char tmp[1000000];
		sprintf ( tmp, "%d", i );
		ans += tmp;
	}
	//cout << ans << ' ' << ans.length ( ) << endl;
}
int main ( ) {
	long long sum, i, s;
	init ( );
	while ( scanf ( "%d", &t ) != EOF ) {
		while ( t-- ) {
			scanf ( "%d", &x );
			for ( sum = s = 0, i = 1; ; ++i ) {
				s += f ( i );
				if ( sum + s >= x ) break;
				sum += s;
			}
			printf ( "%d\n", ans[x-sum-1]-'0' );
			//printf ( "x=%d	x-sum=%d	%d\n", x, x-sum, ans[x-sum-1]-'0' );
		}
	}
}
/*
想问天你在那里
我想问问我自己
一开始我聪明 结束我聪明
聪明的几乎的毁掉了我自己
想问天问大地
或著是迷信问问宿命
放弃所有 抛下所有
让我飘流在安静的夜夜空里
你也不必牵强再说爱我
反正我的灵魂已片片凋落
慢慢的拼凑 慢慢的拼凑
拼凑成一个完全不属於真正的我
你也不必牵强再说爱我
反正我的灵魂已片片凋落
慢慢的拼凑 慢慢的拼凑
拼凑成一个完全不属於真正的我

想问天问大地
或著是迷信问问宿命
放弃所有 抛下所有
让我飘流在安静的夜夜空里
你也不必牵强再说爱我
反正我的灵魂已片片凋落
慢慢的拼凑 慢慢的拼凑
拼凑成一个完全不属於真正的我
你也不必牵强再说爱我
反正我的灵魂已片片凋落
慢慢的拼凑 慢慢的拼凑
拼凑成一个完全不属於真正的我
你也不必牵强再说爱我
反正我的灵魂已片片凋落
慢慢的拼凑 慢慢的拼凑
拼凑成一个完全不属於真正的我
我不愿再放纵
我不愿每天每夜每秒飘流
也不愿再多问再多说再多求我的梦
我不愿再放纵
我不愿每天每夜每秒飘流
也不愿 再多问再多说再多求
我的梦
*/

