#include <stdio.h>
#include <string>
#include <map>
#include <iostream>
using namespace std;
map < char, int > mymap;
string ans[222];
void init ( ) {
	string vowel = "AUEOI";
	string consonant = "JSBKTCLDMVNWFXGPYHQZR";
	int len_vowel = vowel.length ( );
	int len_consonant = consonant.length ( );
	for ( int i = 'A'; i <= 'Z'; ++i )
		if ( i == 'A' || i == 'U' || i == 'E' || i == 'O' || i == 'I' )
			mymap[i] = 21;
		else mymap[i] = 5;
	//for ( int i = 'A'; i <= 'Z'; ++i ) cout << char(i) << mymap[i] << endl;
	string s;
	for ( int j = 1; j < 211; ++j ) {
		if ( j % 2 ) {
			for ( int i = 0; i < len_vowel; ++i )
				if ( mymap[vowel[i]] ) {
					s += vowel[i], mymap[vowel[i]]--;
					break;
				}
			for ( int a = 0; a < j; a += 2 )
				for ( int b = a + 2; b < j; b += 2 )
					if ( s[a] > s[b] ) swap ( s[a], s[b] );
			ans[j] = s;
		}
		else {
			for ( int i = 0; i < len_consonant; ++i )
				if ( mymap[consonant[i]] ) {
					s += consonant[i], mymap[consonant[i]]--;
					break;
				}
			for ( int a = 1; a < j; a += 2 )
				for ( int b = a + 2; b < j; b += 2 )
					if ( s[a] > s[b] ) swap ( s[a], s[b] );
			ans[j] = s;
		}
		//cout << "j=" << j << ":"<<ans[j] << endl;
	}
}

int main ( ) {
	init ( );
	int N, x;
	while ( scanf ( "%d", &N ) != EOF ) {
		for ( int i = 0; i < N; ++i ) {
			scanf ( "%d", &x );
			printf ( "Case %d: %s\n", i + 1, ans[x].c_str ( ) );
		}
	}
}
