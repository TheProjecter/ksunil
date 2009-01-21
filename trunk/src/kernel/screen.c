#include "system.h"

unsigned char *vidmem;
unsigned int screen_width = 80, screen_height = 25;

void clrscr()
{
	unsigned char *vidmem = (unsigned char *)0xB8000;
	const long size = screen_width * screen_height;
	long loop;
	
	for( loop = 0; loop < size; loop++ )
	{
		*vidmem++ = 0;
		*vidmem++ = WHITE_ON_BLACK;
	}
	
	// Set cursor position to 0,0
	gotoxy( 0, 0 );
}

void putch( char c )
{
	unsigned char *vidmem = (unsigned char *)0xb8000;
	unsigned short offset;
	//unsigned long i;
	
	// Get the position of where the character should be
	offset = (cursY * screen_width + cursX);

	// Backspace is handled by moving the cursor one character back, and setting that character to 0 (erasing it, basically)
	if( c == 0x08 )
	{
		cursX -= 2;
		offset = (cursY * screen_width + cursX );
		vidmem[offset] = 0;
		vidmem[offset+1] = WHITE_ON_BLACK;
	}

	// New line
	if( c == '\n' )
	{	
		// Add line and go to the start of that line
		cursY += 2;
		cursX = 0;
	}
	
	// Any character that is greater than or equal to a space is printed
	else if( c >= ' ' )
	{
		vidmem[offset] = c;
		vidmem[offset+1] = WHITE_ON_BLACK;
		cursX += 2;
	}
	
	// Check if the cursor reached the edge of the screen. If so, insert a new line
	if( cursX >= 80 )
	{
		cursX = 0;
		cursY += 2;
	}
	
	// Set the new cursor position
	update_cursor();
}

void prints( char *string )	
{
	int i;
	for( i = 0; i < strlen(string); i++ )
		putch( string[i] );
}
