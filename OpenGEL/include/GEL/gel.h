#if !defined(__gel__) && !defined(_gel_h) && !defined(__gel) \
&& !defined(_gel) && !defined(_gel_)

#define __gel__  1
#define _gel_h	 1
#define __gel	 1
#define _gel	 1
#define _gel_	 1

#ifdef GEL_STATIC
  #define GEL_API extern
#else
#ifdef GEL_IMPL
  #define GEL_API extern __declspec(dllexport)
#else
  #define GEL_API extern __declspec(dllimport)
#endif
#endif

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#define main gel_main

#define GEL_FALSE 0
#define GEL_TRUE 1

// Gel configuration defines
#define GEL_OPENGL                      0x000001
#define GEL_OPENGL_DOUBLEBUFFER         0x000002

#define GEL_DEBUG                       0x000010

// Gel logging stuff defines 
#define GEL_LOG_ERROR                   0x000100
#define GEL_LOG_WARNING                 0x000101
#define GEL_LOG_INFO					0x000102
#define GEL_LOG_CRITICAL				0x000103
#define GEL_LOG_TRACE					0x000104
#define GEL_LOG_PROCESSINFO             0x000105

#define GEL_GROUP_CORE                 	0x000120
#define	GEL_GROUP_SCRIPT				0x000121
#define	GEL_GROUP_GRAPHICES				0x000122
#define	GEL_GROUP_INPUT					0x000123
#define	GEL_GROUP_INICOMPILER			0x000124
#define	GEL_GROUP_AUDIO					0x000125
#define	GEL_GROUP_WINDOW				0x000126
#define	GEL_GROUP_PHYSICS				0x000127

#define GEL_LOG(type, group, format, ...) gel_log(type, group, __FILE__, __FUNCTION__, __LINE__, format, ##__VA_ARGS__)
										
typedef unsigned char gel_boolean;
typedef unsigned char  gel_uchar;
typedef unsigned int    gel_uint;
typedef unsigned char    gel_uint8;
typedef unsigned short    gel_uint16;
typedef unsigned long      gel_uint32;
typedef unsigned long long  gel_uint64;

typedef char gel_char;
typedef int   gel_int;
typedef char   gel_int8;
typedef short   gel_int16;
typedef long     gel_int32;
typedef long long gel_int64;

GEL_API void gel_init();

GEL_API void gel_enable(gel_uint32 flag);
GEL_API void gel_disable(gel_uint32 flag);


GEL_API void gel_log(gel_uint32 type, gel_uint32 group, const char* file, 
	             const char* function, gel_uint line, 
	             const char* format, ...);


typedef struct gel_window gel_window;

GEL_API gel_window* gel_window_create(const gel_char * tilte, gel_uint w, gel_uint h);
GEL_API void gel_window_destory(gel_window* window);
GEL_API gel_uint gel_window_get_width(gel_window* window);
GEL_API gel_uint gel_window_get_height(gel_window* window);
GEL_API const gel_char*    gel_window_get_title(gel_window* window);
GEL_API void gel_window_update();

#ifdef __cplusplus
}
#endif // __cplusplus


#endif

