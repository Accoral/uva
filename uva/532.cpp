#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
char maze[35][35][35];
int dist[35][35][35], vis[35][35][35];
int sx, sy, sz, ex, ey, ez, d, nx, ny, nz, L, R, C, l, r, c;
int dx[] = { 0, 0, 0, 0, +1, -1 };
int dy[] = { 0, 0, -1, +1, 0, 0 };
int dz[] = { -1, +1, 0, 0, 0, 0 };
struct point {
	int i, j, k;
	point ( int x = 0, int y = 0, int z = 0 ) : i ( x ), j ( y ), k ( z ) { };
};
void bfs ( int x, int y, int z ) {
	memset ( vis, 0, sizeof ( vis ) );
	memset ( dist, 0, sizeof ( dist ) );
	//queue < pair < int, pair < int, int > > >q;
	//q.push ( make_pair ( x, make_pair ( y, z ) ) );
	queue < point > q;
	q.push ( point ( x, y, z ) );
	vis[x][y][z] = 1; dist[x][y][z] = 0;
	while ( !q.empty ( ) ) {
		//x = q.front ( ).first; y = q.front ( ).second.first; z = q.front ( ).second.second;
		//q.pop ( );
		point p = q.front ( ); q.pop ( );
		x = p.i; y = p.j; z = p.k;
		for ( d = 0; d < 6; ++d ) {
			nx = x + dx[d]; ny = y + dy[d]; nz = z + dz[d];
			if ( nx >= 0 && nx < L && ny >= 0 && ny < R && nz >= 0 && nz < C  && maze[nx][ny][nz] == '.' && !vis[nx][ny][nz] ) {
				//q.push ( make_pair ( nx, make_pair ( ny, nz ) ) );
				q.push ( point ( nx, ny, nz ) );
				vis[nx][ny][nz] = 1; dist[nx][ny][nz] = dist[x][y][z] + 1;
				if ( !(nx^ex) & !(ny^ey) & !(nz^ez) ) return;
				//if ( nx == ex && ny == ey && nz == ez ) return;
			}
		}
	}
}
int main ( ) {
	char s[35];
	while ( scanf ( "%d%d%d", &L, &R, &C ) != EOF ) {
		if ( !L && !R && !C ) break;
		memset ( maze, '#', sizeof ( maze ) );
		for ( l = 0; l < L; ++l ) {
			for ( r = 0; r < R; ++r ) {
				scanf ( "%s", s );
				for ( c = 0; c < C; ++c ) {
					maze[l][r][c] = s[c];
					if ( s[c] == 'S' ) {
						sx = l, sy = r, sz = c;
					}
					else if ( s[c] == 'E' ) {
						ex = l, ey = r, ez = c;
					}
				}
				maze[l][r][c] = '\0';//maybe could be deleted
			}
		}
		//for ( l = 0; l < L; ++l ) { for ( r = 0; r < R; ++r ) printf ( "%s\n", maze[l][r] ); printf ( "\n" ); }
		maze[ex][ey][ez] = '.';
		bfs ( sx, sy, sz );
		if ( dist[ex][ey][ez] ) printf ( "Escaped in %d minute(s).\n", dist[ex][ey][ez] );
		else printf ( "Trapped!\n" );
	}
}
