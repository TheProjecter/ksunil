#include "system.h"

int cursX = 0, cursY = 0;

void gotoxy( int x, int y )
{
	int position = ( y * screen_width + x );
	out( 0x3D4, 14 );
	out( 0x3D5, position >> 8 );
	out( 0x3D4, 15 );
	out( 0x3D5, position );
}

void update_cursor()
{
	gotoxy( cursX, cursY );
}
