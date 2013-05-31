/*
雪人
好冷
(范)雪已经积的那么深
Merry X'mas to you
我深爱的人
好冷
整个冬天在你家门
Are you my snow man
我痴痴 痴痴的等
雪 一片一片一片一片
拼出你我的缘份
我的爱 因你而生
你的手摸出我的心疼
雪 一片一片一片一片
在天空静静缤纷
眼看春天 就要来了
而我也将 也将不再生存
(王)好冷
雪已经积的那么深
Merry X'mas to you
我深爱的人
好冷
整个冬天在你家门
Am I your snow man
我痴痴 痴痴的等
雪 一片一片一片一片
拼出你我的缘份
我的爱 因你而生
你的手摸出我的心疼
雪 一片一片一片一片
在天空静静缤纷
眼看春天 就要来了
而我也将 也将不再生存
#muice#
(合)雪 一片一片一片一片
拼出你我的缘份
我的爱 因你而生
你的手摸出我的心疼
雪 一片一片一片一片
在天空静静缤纷
眼看春天 就要来了
而我也将 也将不再生存 
*/
#include <stdio.h>
#include <string.h>
void build ( int n, char *s1, char *s2, char *s ) {
	if ( n <= 0 ) return;
	int p = strchr ( s2, s1[0] ) - s2;
	build ( p, s1 + 1, s2, s );
	build ( n-p-1, s1+p+1, s2+p+1, s + p );
	s[n-1] = s1[0];
}
int main ( ) {
	char s1[27], s2[27], ans[27];
	while ( scanf ( "%s%s", s1, s2 ) != EOF ) {
		int n = strlen ( s1 );
		build ( n, s1, s2, ans );
		ans[n] = '\0';
		printf ( "%s\n", ans );
	}
}
