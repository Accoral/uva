#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
string s;
vector < int > v, v_sort;
int main ( ) {
	while ( getline ( cin, s ) ) {
		cout << s << "\n";
		int i = 0, num, j, k, len = s.length ( );
		v.clear ( );
		for ( i = 0; i<len; ++i ) {
			for ( num = 0; s[i] != ' ' && i<len; ++i )
				num *= 10, num += s[i] - '0';
			v.push_back ( num );
		}
		//for ( i = 0; i < v.size ( ); ++i ) cout << v[i] << ' ';cout << "\n";
		v_sort = v;
		sort ( v_sort.begin ( ), v_sort.end ( ) );
		for ( j = v.size ( ) - 1; j >= 0; ) {
			//cout << "j=" << j << endl;
			if ( v != v_sort ) {
				if ( v[j] != v_sort[j] ) {
					for ( i = 0; i < v.size ( ); ++i ) if ( v[i] == v_sort[j] ) break;
					//cout << "****i=" << i << endl;
					if ( i == 0 ) {
						for ( k = 0; k < (j+1) / 2; ++k ) swap ( v[k],v[j-k] );
						cout << v.size ( ) - j << ' ';
						continue;
					}
					cout << v.size ( ) - i << ' ';
					for ( k = 0; k < (i+1) / 2; ++k ) swap ( v[k], v[i-k] );
					continue;
				}
			}
			--j;
		}
		cout << "0\n";
	}
}
