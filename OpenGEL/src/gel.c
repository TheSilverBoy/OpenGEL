#include <stdio.h>
#include <stdlib.h>

#include <GLFW\glfw3.h>

#include "gel_internal.h"

gel_configuration gel_config;

extern int gel_main(int, char*[]);

int main(int argc, char* argv[])
{
	gel_init();
	return gel_main(argc, argv);
}

void gel_init()
{
	glfwInit();
	gel_config.debug_flag = GEL_FALSE;
	gel_config.opengl_flag = GEL_TRUE;
	gel_config.opengl_double_buffer = GEL_TRUE;
}

void gel_enable(gel_uint32 flag)
{
	switch (flag)
	{
	case GEL_OPENGL:
		gel_config.opengl_flag = GEL_TRUE;
		break;
	case GEL_OPENGL_DOUBLEBUFFER:
		gel_config.opengl_double_buffer = GEL_TRUE;
		break;
	case GEL_DEBUG:
		gel_config.debug_flag = GEL_TRUE;
	default:
		break;
	}
	return;
}

void gel_disable(gel_uint32 flag)
{
	switch (flag)
	{
	case GEL_OPENGL:
		gel_config.opengl_flag = GEL_FALSE;
		break;
	case GEL_OPENGL_DOUBLEBUFFER:
		gel_config.opengl_double_buffer = GEL_FALSE;
		break;
	case GEL_DEBUG:
		gel_config.debug_flag = GEL_FALSE;
	default:
		break;
	}
	return;
}


