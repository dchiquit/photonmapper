

#include "OpenGLDisplay.h"

namespace graphics {

	float* _buffer;
	int _width;
	int _height;

	void OpenGL_display(int *argcp, char **argv, float* buffer, int width, int height) {
		_buffer = buffer;
		_width = width;
		_height = height;
		
		glutInit(argcp, argv);
		glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH);
		glutCreateWindow("Photon Mapper");
		glutInitWindowSize(width, height);
		glutInitWindowPosition(50, 50);
		glutReshapeWindow(width, height);
		glutDisplayFunc(_display);
		glutMainLoop();
	}
	
	void _display() {
		glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
		glClear(GL_COLOR_BUFFER_BIT);
	
		// copy our buffer to the screen
		glDrawPixels(_width, _height, GL_RGB, GL_FLOAT, _buffer);
	
		// update the screen
		glFlush();
	}
}