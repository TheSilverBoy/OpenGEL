#ifndef GEL_INTERNAL_H
#define GEL_INTERNAL_H

#include "GEL\gel.h"

#undef main

typedef struct {
	gel_boolean debug_flag;
	gel_boolean opengl_flag;
	gel_boolean opengl_double_buffer;
}gel_configuration;


GEL_API gel_configuration gel_config;


#endif // GEL_INTERNAL_H
