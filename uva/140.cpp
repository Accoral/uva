#include <cstdio>
#include <cstring>
int G[30][30], n, ans, tmp[10], vis[30], map[30], v[30];
void dfs ( int cur ) {
	if ( cur == n ) {
		//for ( int i = 0; i < n; ++i ) printf ( "%d ", tmp[i] );printf ( "\n" );
		int dis = 0;
		for ( int i = 0; i < n; ++i ) for ( int j = i+1; j < n; ++j ) {
			//printf ( "G[%d][%d] = %d\n", tmp[i], tmp[j], G[tmp[i]][tmp[j]] );
			if ( G[tmp[i]][tmp[j]] && dis < j-i ) dis = j-i; //printf ( "j=%d i=%d dis=%d	G[%d][%d]\n", j, i, dis, tmp[i],tmp[j] );
		}
		if ( dis < ans ) {
			ans = dis;
			memcpy ( v, tmp, sizeof(tmp) );
			//for ( int i = 0; i < n; ++i ) printf ( "%d ", tmp[i] );printf ( "\n" );
		}
		return;
	}
	for ( int i = 0; i < cur; ++i ) for ( int j = i+1; j < cur; ++j ) if ( G[tmp[i]][tmp[j]] && j-i > ans ) return;
	for ( int i = 0; i < 26; ++i ) {
		if ( !vis[i] && map[i] ) {
			vis[i] = 1;
			tmp[cur] = i;
			dfs ( cur+1 );
			vis[i] = 0;
		}
	}
}
int main ( ) {
	char s[1000];
	int i, j, cnt;
	while ( scanf ( "%s", s ) != EOF && s[0] != '#' ) {
		int flag = 1, tmp;
		memset ( G, 0, sizeof(G) );
		memset ( map, 0, sizeof(map) );
		for ( n = i = 0; i < strlen(s); ++i ) {
			if ( s[i] == ':' ) continue;
			else if ( flag ) tmp = s[i], flag = 0, map[s[i]-'A']++;
			else if ( s[i] != ';' ) G[tmp-'A'][s[i]-'A'] = G[s[i]-'A'][tmp-'A'] = 1, map[s[i]-'A']++;
			else flag = 1;
		}
		for ( i = 0; i < 26; ++i ) if ( map[i] ) ++n;
		ans = 0x7fffffff;
		memset ( vis, 0, sizeof(vis) );
		dfs ( 0 );
		for ( i = 0; i < n; ++i ) printf ( "%c ", v[i]+'A' );
		printf ( "-> %d\n", ans );
	}
}
