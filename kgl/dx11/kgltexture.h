#pragma once

class KGLTexture
{
public:
    KGLTexture(const std::wstring& filename, ID3D11Device* device);
    KGLTexture(const void* buffer, int size, ID3D11Device* device);
    KGLTexture(const void* buffer, DXGI_FORMAT format, unsigned int width, unsigned int height, ID3D11Device* device);
    void initSize();
private:
    ID3D11ShaderResourceView* shaderResourceView;
    KGLTexture::ImageFileFormat fileFormat;
    DXGI_FORMAT textureFormat;
    std::wstring fileName;
    unsigned int width;
    unsigned int height;
    bool ownsShaderResourceView;
};