#pragma once

class KGLCubeMap
{
void KGLCubeMap(ID3D11Device *device, unsigned int size, unsigned int format, unsigned int mips);
void ~KGLCubeMap();

};