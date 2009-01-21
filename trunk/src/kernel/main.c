#include "system.h"

void kmain()
{
	char string[] = "This is a test string!\nAin't it pretty??\b";
	clrscr();
	memset( string, '-', 4 );
	prints( string );
}
