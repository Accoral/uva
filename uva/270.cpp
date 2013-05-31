#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
using namespace std;
pair < int, int > p;
vector < pair < int, int > > v;
int main ( ) {
	int N, n, first = 0, x, y, i, j, k, sum, ans;
	string s;
	while ( cin >> N ) {
		getline ( cin, s );
		getline ( cin, s );
		while ( N-- ) {
			if ( first ) cout << "\n";
			else first = 1;
			v.clear ( );
			while ( getline ( cin, s ) ) {
				if ( s == "" ) break;
				sscanf ( s.c_str ( ), "%d %d", &x, &y );
				v.push_back ( make_pair ( x, y ) );
			}
			ans = sum = 0;
			for ( i = 0; i < v.size ( ); ++i )
				for ( j = i + 1; j < v.size ( ); ++j ) {
					for ( sum = k = 0; k < v.size ( ); ++k )
						if ( (v[j].second-v[i].second)*(v[k].first-v[i].first)==(v[k].second-v[i].second)*(v[j].first-v[i].first))
							++sum;
					ans = max ( ans, sum );
				}
				cout << ans << "\n";
		}
	}
}
