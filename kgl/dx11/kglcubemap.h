#pragma once

class KGLCubeMap
{
public:
    KGLCubeMap(ID3D11Device* device, unsigned int size, unsigned int format, unsigned int mips);
    ~KGLCubeMap();
};