#include "OpenGL.h"



COpenGL::COpenGL()
{
	renderer = nullptr;
}


COpenGL::~COpenGL()
{
	Cleanup();
}

bool COpenGL::Initialize()
{

	if ( !glfwInit() )
	{
		fprintf( stderr, "Failed to Initialize GLFW\n" );
		return false;
	}

	glfwWindowHint( GLFW_SAMPLES, 4 ); // 4x antialiasing
	glfwWindowHint( GLFW_CONTEXT_VERSION_MAJOR, 3 ); // We want OpenGL 3.3
	glfwWindowHint( GLFW_CONTEXT_VERSION_MINOR, 3 ); // Open a Window and create its OpenGL Context
	glfwWindowHint( GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE ); // To make MacOS happy; should not be needed
	glfwWindowHint( GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE ); // We don't want the old OpenGL

	/*if ( renderer == nullptr || !renderer->Initialize() )
	{
		return false;
	}*/

	return true;
}

bool COpenGL::CreateWindow( int width, int height, char * title )
{

	mainWindow = glfwCreateWindow( width, height, title, NULL, NULL );
	if ( mainWindow == NULL )
	{
		fprintf( stderr, "Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version of the tutorials.\n" );
		glfwTerminate();
		return false;
	}

	glfwMakeContextCurrent( mainWindow ); // Initialize GLEW
	glewExperimental = true; // Needed in core profile

	if ( glewInit() != GLEW_OK )
	{
		fprintf( stderr, "Failed to initialize GLEW\n" );
		return false;
	}

	// Ensure we can capture the escape key being pressed below
	glfwSetInputMode( mainWindow, GLFW_STICKY_KEYS, GL_TRUE );

	// Dark blue background
	glClearColor( 0.0f, 0.0f, 0.4f, 0.0f );

	return true;
}

void COpenGL::GLRender()
{
	
	do {
		renderer->Render();
		glfwSwapBuffers( mainWindow );
		glfwPollEvents();
	} while ( glfwGetKey( mainWindow, GLFW_KEY_ESCAPE ) != GLFW_PRESS &&
			  glfwWindowShouldClose( mainWindow ) == 0 );
}

void COpenGL::Cleanup()
{
	if ( renderer != nullptr ) {
		renderer->Cleanup();
	}
	glfwTerminate();
}
