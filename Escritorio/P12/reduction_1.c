#include <stdio.h>

#include <time.h>
// para el tiempo

#include <stdlib.h>
// para system()

#include <time.h>

#include <omp.h>

int main(){
	srand( time( NULL ) );
	int acum = 0;
	int n = 15;
	int a[ n ];
	for( size_t i = 0; i < n; i++)
		a[ i ] = 1 + rand() % ( 21 - 1 );

	#pragma omp parallel for shared( a, n ) reduction( +: acum )
		for( size_t i = 0; i < n; i++ ){
			acum += a[ i ];
			printf( "Acum: %d\n", acum);
		}

	printf( "Total %d\n", acum );
}
