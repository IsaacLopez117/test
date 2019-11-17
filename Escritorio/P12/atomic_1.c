#include <stdio.h>

#include <stdlib.h>
// para system() y rand() 5

#include <time.h>

#include <omp.h>

#define TAM 10

int main()
{
	int cont = 0, b = 1, i , n = 10;
	#pragma omp parallel for num_threads( 4 ) shared( n, cont, b) private( i )
	for( i = 0; i < n; ++i ){
		//#pragma omp atomic
   		cont += b++;
	} // --- Implicit barrier
	printf( "cont = %d, b = %d\n", cont, b );
}