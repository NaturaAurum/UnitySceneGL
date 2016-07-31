#pragma once

#include "LoadShader.h"

class IRenderer
{
public:
	IRenderer();
	virtual ~IRenderer() = 0;

	virtual bool Initialize() = 0;
	virtual void Render() = 0;
	virtual void Cleanup() = 0;
};

