#include "OpenGL.h"
#include "Triangle.h"

int main( void )
{
	COpenGL* openGL = new COpenGL();


	if ( !openGL->Initialize() )
	{
		return -1;
	}

	if ( !openGL->CreateWindow( 1024, 768, "Unity Renderer" ) )
	{
		return -1;
	}

	openGL->SetRenderer( new CTriangle() );

	openGL->GLRender();

	openGL->Cleanup();
}