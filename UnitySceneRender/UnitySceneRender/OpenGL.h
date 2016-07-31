#pragma once

#include <stdio.h>
#include <stdlib.h>

#include "GL.h"

#include "IRenderer.h"

class COpenGL
{

private:
	GLFWwindow* mainWindow;
	IRenderer* renderer;

public:
	COpenGL( void );
	~COpenGL( void );

	bool Initialize();
	bool CreateWindow( int width, int height, char* title );
	void GLRender();
	void Cleanup();

	inline void SetRenderer( IRenderer* r ) {
		renderer = r;
		renderer->Initialize();
	}
};

