#include <stdio.h>


#include "sdlJeu.h"

int main ( int argc, char** argv )
{
    sdlJeu sj;
	sdljeuInit( &sj );
	sdljeuBoucle( &sj );
	sdljeuDetruit( &sj );


	printf("Fin\n");
	return 0;
}
