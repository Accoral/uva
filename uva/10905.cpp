#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main ( ) {
	int n, i, j;
	string s;
	vector < string > v;
	while ( cin >> n && n ) {
		v.clear ( );
		for ( i = 0; i < n; ++i ) {
			cin >> s;
			v.push_back ( s );
		}
		for ( i = 0; i < n; ++i )
			for ( j = i + 1; j < n; ++j ) {
				if ( v[i] + v[j] < v[j] + v[i] )
					swap ( v[i], v[j] );
			}
		for ( i = 0; i < n; ++i ) cout << v[i];
		cout << "\n";
	}
}
