#pragma once

#include <string>
#include <d3d11.h>
#include <d3dx11tex.h>

class KGLTexture
{
public:
    enum class ImageFileFormat
    {
        eUnknown = 0,
        eBMP,
        eJPG,
        ePNG,
        eDDS
    };

    KGLTexture(const std::wstring &filename, ID3D11Device *device);
    KGLTexture(const void *buffer, int size, ID3D11Device *device);
    KGLTexture(const void *buffer, DXGI_FORMAT format, unsigned int width, unsigned int height, ID3D11Device *device);
    void initSize();

private:
    ID3D11ShaderResourceView *shaderResourceView = nullptr;
    KGLTexture::ImageFileFormat fileFormat = ImageFileFormat::eUnknown;
    DXGI_FORMAT textureFormat = DXGI_FORMAT_UNKNOWN;
    std::wstring fileName;
    unsigned int width = 0;
    unsigned int height = 0;
    bool ownsShaderResourceView;
};