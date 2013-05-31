#include <stdio.h>
int main ( ) {
	int H, U, D, F, day;
	while ( scanf ( "%d%d%d%d", &H, &U, &D, &F ) != EOF && H ) {
		double initial_height = 0;
		double distance_climbed = U;
		double height_after_climbing = initial_height + distance_climbed;
		double height_after_sliding = height_after_climbing - D;
		day = 1;
		for ( ; ; ++day ) {
			if ( height_after_climbing > H || height_after_sliding < 0  ) break;
			initial_height = height_after_sliding;
			distance_climbed = distance_climbed - U * F / 100.0;
			if ( distance_climbed < 0 ) distance_climbed = 0;
			height_after_climbing = initial_height + distance_climbed;
			height_after_sliding = height_after_climbing - D;
		}
		if ( height_after_climbing > H ) printf ( "success" );
		else printf ( "failure" );
		printf ( " on day %d\n", day );
	}
}
