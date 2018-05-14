#ifndef GEL_LOG_H
#define GEL_LOG_H

#include "gel_internal.h"

#include <stdarg.h>

typedef struct gel_log_entry gel_log_entry;

#define ALL_LOG_NAME()                       \
        LOG(Error)                           \
        LOG(Info)                            \
        LOG(Warning)                         \
        LOG(Trace)                           \
        LOG(Critical)                        \
        LOG(ProcessInfo)                     \

#define ALL_GROUP_NAME()                         \
		GRP(Core)								 \
		GRP(Script)								 \
		GRP(Graphices)							 \
		GRP(Input)								 \
		GRP(IniCompiler)					     \
		GRP(Audio)								 \
		GRP(Window)								 \
		GRP(Physics)									 


typedef enum {
	Error =          0x000100,
	Warning =        0x000101,
	Info =           0x000102,
	Critical =       0x000103,
	Trace =          0x000104,
	ProcessInfo =    0x000105
}log_type;

typedef enum {
	Core =           0x000120,
	Script =         0x000121,
	Graphices =      0x000122,
	Input =          0x000123,
	IniCompiler =    0x000124,
	Audio =          0x000125,
	Window =         0x000126,
	Physics =        0x000127
}group_type;

GEL_API gel_log_entry* gel_create_entry(gel_uint32 type,gel_uint32 group, const char* file, 
	                                const char* function, gel_uint line, 
	                                const char* format);

GEL_API void gel_delete_entry(gel_log_entry* entry);



#endif // GEL_LOG_H

