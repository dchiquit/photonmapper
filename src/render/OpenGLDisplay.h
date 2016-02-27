
#include <GL/glut.h>

#ifndef SRC_OPENGLDISPLAY_H_
#define SRC_OPENGLDISPLAY_H_

#include "Geometry.h"


namespace graphics {

	extern float* _buffer;
	extern int _width;
	extern int _height;
	
	void _display();
	void OpenGL_display(int *argcp, char **argv, float* buffer, int width, int height);
	

}

#endif /* SRC_OPENGLDISPLAY_H_ */
