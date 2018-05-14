#include "..\OpenGEL\include\GEL\gel.h"
#define _CRT_SECURE_NO_WARNINGS
#include <tchar.h>
#include <string.h>
#include <stdlib.h>


int main(int argc, char* argv[]) {
	gel_enable(GEL_DEBUG);
	gel_disable(GEL_DEBUG);
	gel_window* win = gel_window_create("Hello Rajat yadav", 600, 400);
	system("PAUSE");
	return 1;
}




