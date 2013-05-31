#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int MAXN = 30;
char maze[MAXN][MAXN];
int M, N, vis[MAXN][MAXN][4][5], time[MAXN][MAXN][4][5], sx, sy, tx, ty, ans;
int dx[] = { -1, 0, +1, 0 };
int dy[] = { 0, -1, 0, +1 };
struct node {
	int x, y, dir, color;
	node ( int a, int b, int c, int d ) : x(a), y(b), dir(c), color(d) { }
};
void bfs ( ) {
	memset ( vis, 0, sizeof ( vis ) );
	queue < node > q;
	q.push ( node ( sx, sy, 0, 0 ) );
	vis[sx][sy][0][0] = 1;
	time[sx][sy][0][0] = 0;
	int x, y, dir, color, nx, ny, ndir, ncolor;
	while ( !q.empty ( ) ) {
		node p = q.front ( ); q.pop ( );
		x = p.x, y = p.y, dir = p.dir, color = p.color;
		if ( !(x^tx) & !(y^ty) & !color ) {
			printf ( "minimum time = %d sec\n", time[x][y][dir][color] );
			return;
		}
		for ( int i = 0; i < 3; ++i ) {// i==0 foreword; i==1 left; i==2 right;	
			if ( i == 0 ) nx = x + dx[dir], ny = y + dy[dir], ndir = dir, ncolor = (color+1)%5;
			else {
				nx = x, ny = y, ndir = (dir+1)%4, ncolor = color;
				if ( i == 2 ) ndir = (dir+3)%4;
			}
			if ( nx >= 0 && nx < M && ny >= 0 && ny < N && maze[nx][ny] != '#' && !vis[nx][ny][ndir][ncolor] ) {
				q.push ( node ( nx, ny, ndir, ncolor ) );
				vis[nx][ny][ndir][ncolor] = 1;
				time[nx][ny][ndir][ncolor] = time[x][y][dir][color] + 1;
			}
		}
	}
	printf ( "destination not reachable\n" );
}
int main ( ) {
	char s[MAXN];
	int i, j, cases = 0;
	while ( scanf ( "%d%d", &M, &N ) != EOF && ( M || N ) ) {
		if ( cases ) printf ( "\n" );
		printf ( "Case #%d\n", ++cases );
		for ( i = 0; i < M; ++i ) {
			scanf ( "%s", s );
			for ( j = 0; j < N; ++j ) {
				maze[i][j] = s[j];
				if ( s[j] == 'S' ) sx = i, sy = j;
				else if ( s[j] == 'T' ) tx = i, ty = j;
			}
		}
		bfs ( );
	}
}
