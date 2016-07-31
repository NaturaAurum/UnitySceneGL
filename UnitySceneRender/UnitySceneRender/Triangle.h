#pragma once

#include "GL.h"

#include "IRenderer.h"

class CTriangle : public IRenderer
{
private:
	char* vertexShaderPath;
	char* fragmentShaderPath;

	GLuint vertexArrId;
	GLuint shader;

	GLuint vertexBuffer;

public:
	CTriangle( void );
	~CTriangle( void );

	virtual bool Initialize();
	virtual void Render();
	virtual void Cleanup();
};

