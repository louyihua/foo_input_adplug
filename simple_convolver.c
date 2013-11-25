#include "simple_convolver.h"

#include <stdlib.h>
#include <string.h>

static const double impulse[17] =
{
	 0.0137501651,  0.0501893545,  0.0544352420,  0.1513992285,
	 0.1350756025, -0.0251918081, -0.0545919437, -0.1161821503,
	 0.0350159509,  0.0812958418,  0.0458840981,  0.1090441483,
	 0.0563217198,  0.1970305039,  0.2140730189,  0.0352126356,
	 0.0172383921
};

typedef struct convolver_state
{
	double buffer[16];
	int pointer;
} convolver_state;

void * convolver_create()
{
	void * state = calloc( 1, sizeof( convolver_state ) );
	return state;
}

void convolver_delete( void * state )
{
	if ( state )
		free( state );
}

void convolver_clear( void * state )
{
	if ( state )
		memset( state, 0, sizeof( convolver_state ) );
}

short convolver_process( void * _state, short sample )
{
	convolver_state * state = ( convolver_state * ) _state;
	double out_sample = (double)sample * impulse[0];
	int clipped_sample;
	int i, j;
	if ( !state ) return 0;
	for ( i = 1, j = state->pointer; i < 17; ++i, ++j )
	{
		out_sample += impulse[i] * state->buffer[j & 15];
	}
	state->pointer = (state->pointer - 1) & 15;
	state->buffer[state->pointer] = (double)sample;
	clipped_sample = (int)out_sample;
	if ( (unsigned)(clipped_sample + 0x8000) & 0xffff0000 )
		clipped_sample = (clipped_sample >> 31) ^ 0x7fff;
	return (short)clipped_sample;
}
