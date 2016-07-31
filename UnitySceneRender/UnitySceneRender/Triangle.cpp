#include "Triangle.h"



CTriangle::CTriangle()
{
	vertexShaderPath = "TrivertexShader.vertexshader";
	fragmentShaderPath = "TrifragmentShader.fragmentShader";

	vertexArrId = NULL;
	shader = NULL;
	vertexBuffer = NULL;
}


CTriangle::~CTriangle()
{
	vertexShaderPath = nullptr;
	fragmentShaderPath = nullptr;
}

bool CTriangle::Initialize() {

	glGenVertexArrays( 1, &vertexArrId );
	glBindVertexArray( vertexArrId );

	shader = CLoadShader::LoadShader( vertexShaderPath, fragmentShaderPath );

	GLfloat triData[] = {
		-1.0f, -1.0f, 0.0f,
		1.0f, -1.0f, 0.0f,
		0.0f, 1.0f, 0.0f,
	};

	glGenBuffers( 1, &vertexBuffer );
	glBindBuffer( GL_ARRAY_BUFFER, vertexBuffer );
	glBufferData( GL_ARRAY_BUFFER, sizeof( triData ), triData, GL_STATIC_DRAW );

	return true;
}

void CTriangle::Render() {
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
	glUseProgram( shader );
	glEnableVertexAttribArray( 0 );
	glBindBuffer( GL_ARRAY_BUFFER, vertexBuffer );
	glVertexAttribPointer(
		0,
		3,
		GL_FLOAT,
		GL_FALSE,
		0,
		( void* )0
	);
	glDrawArrays( GL_TRIANGLES, 0, 3 );
	glDisableVertexAttribArray( 0 );
}

void CTriangle::Cleanup() {
	glDeleteBuffers( 1, &vertexBuffer );
	glDeleteVertexArrays( 1, &vertexArrId );
	glDeleteProgram( shader );
}
