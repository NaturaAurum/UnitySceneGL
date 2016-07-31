#pragma once
#ifndef SHADER_H_
#define SHADER_H_

#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

#include <stdlib.h>
#include <string.h>
#include <GL\glew.h>

class CLoadShader
{
public:
	CLoadShader( void );
	~CLoadShader( void );

	static GLuint LoadShader( const char* vertexFilePath, const char* fragmentFilePath );
};
#endif

