#include "window_common.h"

#include <stdio.h>
#include <stdlib.h>


GEL_API gel_window* gel_window_create(const gel_char * title, gel_uint w, gel_uint h)
{
	// declare a gel_window instance
	gel_window* win = NULL;
	// allocate the gel_window instance
	win = (gel_window*)malloc(sizeof* win);
	// create the glfw window of the gel_window instance
	win->window = glfwCreateWindow(w, h, title, NULL, NULL);

	// if gel debug is enabled 
	if (gel_config.debug_flag) {
		// if window not created successfully 
		if (win->window == NULL) {
			// log window creation failed
			GEL_LOG(GEL_LOG_ERROR, GEL_GROUP_WINDOW, "Window creation failed!");
			// return null
			return NULL;
		}
		// else
		else {
			// log window creation info
			GEL_LOG(GEL_LOG_INFO, GEL_GROUP_WINDOW, "Window created sucessfully with the following"
				" attribs title: title=%s, dimensions: w=%i, h=%i", title, w, h);
			// return the gel_window_instance
			return win;
		}
	}

	// return the gel_window instance
	return win;
}
GEL_API void gel_window_destory(gel_window* window)
{

}
GEL_API gel_uint gel_window_get_width(gel_window* window)
{

}
GEL_API gel_uint gel_window_get_height(gel_window* window)
{

}
GEL_API const gel_char*    gel_window_get_title(gel_window* window)
{

}
GEL_API void gel_window_update()
{

}




