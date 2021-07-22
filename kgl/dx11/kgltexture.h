#pragma once

class KGLTexture
{
void KGLTexture(const std::wstring *filename, ID3D11Device *device);
void KGLTexture(const void *buffer, int size, ID3D11Device *device);
void KGLTexture(const void *buffer, DXGI_FORMAT format, unsigned int width, unsigned int height, ID3D11Device *device);
void initSize();

};