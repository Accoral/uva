#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;
struct Team{
	int points, wins, ties, losses, goals_scored, goals_agains, goal_difference, game_played;
	string name;
}team[35];
bool mycmp ( Team x, Team y ) {
	if ( x.points != y.points ) return x.points > y.points;
	if ( x.wins != y.wins ) return x.wins > y.wins;
	if ( x.goal_difference != y.goal_difference ) return x.goal_difference > y.goal_difference;
	if ( x.goals_scored != y.goals_scored ) return x.goals_scored > y.goals_scored;
	if ( x.game_played != y.game_played ) return x.game_played < y.game_played;
	string s1, s2;
	for ( int i = 0; x.name[i]; ++i ) s1 += tolower ( x.name[i] );
	for ( int i = 0; y.name[i]; ++i ) s2 += tolower ( y.name[i] );
	return s1 < s2;
}
int main ( ) {
	int N, T, G, first = 0;
	string tournament_name, s, line;
	while ( cin >> N ) {
		getline ( cin, line );
		while ( N-- ) {
			if ( first ) printf ( "\n" );
			else first = 1;
			getline ( cin, tournament_name );
			printf ( "%s\n", tournament_name.c_str ( ) );
			cin >> T;
			getline ( cin, line );
			for ( int i = 0; i < T; ++i ) {
				getline ( cin, team[i].name );
				team[i].points = team[i].wins = team[i].ties = team[i].losses = team[i].goals_scored = team[i].goals_agains = team[i].goal_difference = team[i].game_played = 0;
			}
			cin >> G;
			getline ( cin, line );
			for ( int i = 0; i < G; ++i ) {
				getline ( cin, s );
				//cout << "s=" << s << endl;
				string s1, s2, tmp;
				int score1, score2, k, len = s.length ( );
				for ( k = 0; s[k] != '#' && k < len; ++k ) s1 += s[k];
				for ( ++k; s[k] != '#' && k < len; ++k ) tmp += s[k];
				for ( ++k; k < len; ++k ) s2 += s[k];
				sscanf ( tmp.c_str ( ), "%d@%d", &score1, &score2 );
				//cout << s1 << "..." << tmp << "..." << s2 << endl;
				//cout << score1 << "..." << score2 << endl;

				for ( k = 0; k < T; ++k ) {
					if ( team[k].name == s1 ) {
						team[k].goals_scored += score1;
						team[k].goals_agains += score2;
						team[k].goal_difference = team[k].goals_scored - team[k].goals_agains;
						team[k].game_played++;
						if ( score1 > score2 ) {
							team[k].points += 3;
							team[k].wins++;
						}
						else if ( score1 == score2 ) {
							team[k].points += 1;
							team[k].ties++;
						}
						else team[k].losses++;
						break;
					}
				}
				for ( k = 0; k < T; ++k ) {
					if ( team[k].name == s2 ) {
						team[k].goals_scored += score2;
						team[k].goals_agains += score1;
						team[k].goal_difference = team[k].goals_scored - team[k].goals_agains;
						team[k].game_played++;
						if ( score1 < score2 ) {
							team[k].points += 3;
							team[k].wins++;
						}
						else if ( score1 == score2 ) {
							team[k].points += 1;
							team[k].ties++;
						}
						else team[k].losses++;
						break;
					}
				}
			}
			sort ( team, team + T, mycmp );
			//for ( int i = 0; i < T; ++i ) { cout << team[i].name<<" "<<team[i].points << " "; cout << team[i].game_played << " " << team[i].wins << " "<< team[i].ties <<" "<< team[i].losses<<" "<<team[i].goal_difference<<" " <<team[i].goals_scored<< " " << team[i].goals_agains <<endl; }
			for ( int i = 0; i < T; ++i )
				//printf ( "1) Brazil 6p, 3g (2-0-1), 3gd (6-3)\n" );
			printf ( "%d) %s %dp, %dg (%d-%d-%d), %dgd (%d-%d)\n",i+1,team[i].name.c_str(),team[i].points,team[i].game_played,team[i].wins,team[i].ties,team[i].losses,team[i].goal_difference,team[i].goals_scored,team[i].goals_agains);
		}
	}
}
