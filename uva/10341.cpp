#include <math.h>
#include <stdio.h>
int p, r, q, s, t, u;
double f ( double x ) {
	return p * exp ( x * -1 ) + q * sin ( x ) + r * cos ( x ) + s * tan ( x ) + t * x * x + u;
}
int main ( ) {
	while ( scanf ( "%d%d%d%d%d%d", &p, &q, &r, &s, &t, &u ) != EOF ) {
		double x = 0, y = 1;
		if ( f ( x ) * f ( y ) > 0 ) printf ( "No solution\n" );
		else {
			while ( y - x > 1e-7 ) {
				double m = x + ( y - x ) / 2;
				//printf ( "x=%lf,y=%lf,m=%lf,f=%lf\n", x,y,m,f );
				if ( f ( m ) < 1e-7 ) y = m;
				else x = m;
			}
			//printf ( "f=%lf, x=%lf*****\n", f, x );
			printf ( "%.4lf\n", x );
		}
	}
}
