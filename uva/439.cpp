#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
int dx[] = { -2, -2, +2, +2, -1, +1, -1, +1 };
int dy[] = { -1, +1, -1, +1, -2, -2, +2, +2 };
int dist[8][8], vis[8][8], x, y, d, ex, ey;
char s1[3], s2[3];
void bfs ( int x, int y ) {
	memset ( vis, 0, sizeof ( vis ) );
	memset ( dist, 0, sizeof ( dist ) );
	//pair < int, int > q[10*10];
	int front = 0, rear = 0;
	queue < pair < int, int > > q;
	pair < int, int > p ( x, y );
	//q[rear++] = p;
	q.push ( p );
	dist[x][y] = 0; vis[x][y] = 1;
	while ( !q.empty ( ) ) {
	//while ( front < rear ) {
		p = q.front ( ); q.pop ( );
		//p = q[front++];
		x = p.first, y = p.second;
		for ( d = 0; d < 8; ++d ) {
			int nx = x + dx[d], ny = y + dy[d];
			if ( nx >= 0 && nx < 8 && ny >= 0 && ny < 8 && !vis[nx][ny] ) {
				q.push ( make_pair ( nx, ny ) );
				//q[rear++] = make_pair ( nx, ny );
				vis[nx][ny] = 1; dist[nx][ny] = dist[x][y] + 1;
				if ( !(nx ^ ex) & !(ny ^ ey) ) return;
			}
		}
	}
}
int main ( ) {
	while ( scanf ( "%s%s", s1, s2 ) != EOF ) {
		ex = s2[0] - 'a', ey = s2[1] - '1';
		bfs ( s1[0] - 'a', s1[1] - '1' );
		printf ( "To get from %s to %s takes %d knight moves.\n", s1, s2, dist[ex][ey] );
	}
}
