#include <iostream>
#include <map>
using namespace std;
map < pair < int, int >, int > mymap;
map < pair < int, int >, int > :: iterator it;
int main ( ) {
	int n, x, y, i, flag;
	pair < int, int > p1, p2;
	while ( cin >> n && n ) {
		mymap.clear ( );
		for ( i = 0; i < n; ++i ) {
			cin >> x >> y;
			p1 = make_pair ( x, y );
			p2 = make_pair ( y, x );
			if ( mymap.count ( p2 ) && mymap[p2] > 0 ) mymap[p2]--;
			else if ( mymap.count ( p1 ) == 0 ) mymap[p1] = 1;
			else mymap[p1]++;
			//cout << "i=" << i << ":\n"; for ( it = mymap.begin ( ); it != mymap.end ( ); ++it ) cout << it->first.first << ' ' << it->first.second << ' ' << it->second << "\n";
		}
		flag = 1;
		for ( it = mymap.begin ( ); it != mymap.end ( ); ++it )
			if ( it->second ) {
				cout << "NO\n";
				flag = 0;
				break;
			}
		if ( flag ) cout << "YES\n";
	}
}
